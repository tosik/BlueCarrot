
#include "for/win/iRenderer.h"
#include "for/win/MainFunction.h"
#include <cassert>
#include "basic/GlobalInstance.h"
#include "for/win/DeviceInformation.h"
#include "for/win/iTexture.h"
#include "debug/Debug.h"


namespace graphics
{
	void Renderer::CreateImpl()
	{
		m_pImpl = new iRenderer();
	}
	void Renderer::DestroyImpl()
	{
		delete reinterpret_cast<iRenderer *>(m_pImpl);
	}

	void Renderer::InitializeDevice()
	{
		reinterpret_cast<iRenderer *>(m_pImpl)->InitializeWindows(g_hMainInstance, g_nWinMode, WinProc);
		reinterpret_cast<iRenderer *>(m_pImpl)->Initialize3D();
	}

	void Renderer::FinalizeDevice()
	{
		reinterpret_cast<iRenderer *>(m_pImpl)->Finalize3D();
		reinterpret_cast<iRenderer *>(m_pImpl)->FinalizeWindows();
	}

	void Renderer::Begin()
	{
		reinterpret_cast<iRenderer *>(m_pImpl)->Begin();
	}

	void Renderer::End()
	{
		reinterpret_cast<iRenderer *>(m_pImpl)->End();
	}

	float Renderer::GetAspect()
	{
		return reinterpret_cast<iRenderer *>(m_pImpl)->GetAspect();
	}

	void Renderer::ChangeAspect(bool wide)
	{
		reinterpret_cast<iRenderer *>(m_pImpl)->ChangeAspect(wide);
	}

	bool Renderer::IsWide()
	{
		return reinterpret_cast<iRenderer *>(m_pImpl)->IsWide();
	}

	bool Renderer::ProcessMessage()
	{
		return reinterpret_cast<iRenderer *>(m_pImpl)->ProcessMessage();
	}

	void Renderer::SetScreenSize(const utility::Size<int> & size)
	{
		reinterpret_cast<iRenderer *>(m_pImpl)->SetScreenSize(size);
	}


	iRenderer::iRenderer()
		: m_IsFirstFrame(true)
		, m_IsWide(false)
		, m_Aspect(4.f/3.f)
		, m_IsFullScreen(false)
	{
	}

	iRenderer::~iRenderer()
	{
	}

	void iRenderer::InitializeWindows(HINSTANCE hThisInst, int nWinMode, WNDPROC pWinProcFunction)
	{
		// default
		m_Name	= L"WinAppName";
		m_Title	= L"WinAppTitle";
		m_WindowStyle = WS_OVERLAPPED | WS_SYSMENU | WS_BORDER;
		m_IsFullScreen = false;


		// インスタンスのハンドルを記録
		m_hInstance = hThisInst;


		//ウィンドウクラス構造体
		WNDCLASSEX wc;

		// ウィンドウクラスを定義する
		wc.cbSize = sizeof(WNDCLASSEX);
		wc.style = NULL;
		wc.lpfnWndProc = pWinProcFunction;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hInstance = m_hInstance;
		wc.hIcon = NULL;
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);
		wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
		wc.lpszMenuName = NULL;
		wc.lpszClassName = m_Name.c_str();
		wc.hIconSm = NULL;

		// ウィンドウクラスの登録
		int atom = RegisterClassEx(&wc);
		if ( atom == 0 )
		{
			DWORD error_id = GetLastError();
			throw error_id;
		}

		utility::Size<int> client_area = m_ScreenSize;
		client_area.width	+=	GetSystemMetrics(SM_CXEDGE)
							+	GetSystemMetrics(SM_CXBORDER)
							+	GetSystemMetrics(SM_CXFIXEDFRAME);
		client_area.height	+=	GetSystemMetrics(SM_CYEDGE)
							+	GetSystemMetrics(SM_CYBORDER)
							+	GetSystemMetrics(SM_CXFIXEDFRAME)
							+	GetSystemMetrics(SM_CYCAPTION);

		// ウィンドウを生成する
		m_hwnd = CreateWindow(
			m_Name.c_str(),			// ウィンドウクラスの名前
			m_Title.c_str(),		// ウィンドウタイトル
			m_WindowStyle,			// ウィンドウスタイル
			0,						// ウィンドウの左角Ｘ座標
			0,						// ウィンドウの左角Ｙ座標
			client_area.width,		// ウィンドウの幅
			client_area.height,		// ウィンドウの高さ
			NULL,					// 親ウィンドウ（なし）
			NULL,					// メニュー（なし）
			m_hInstance,			// このプログラムのインスタンスのハンドル
			NULL					// 追加引数（なし）
		);
		DWORD err = GetLastError();
		assert ( m_hwnd != NULL );

		// ウィンドウを表示
		ShowWindow(m_hwnd, nWinMode);

		// ウィンドウの更新
		UpdateWindow(m_hwnd);


		// 最小タイマ分解能を指定
		timeBeginPeriod(1);
	}

	void iRenderer::FinalizeWindows()
	{
		timeEndPeriod(1);
	}

	void iRenderer::Initialize3D()
	{
		// DirectX オブジェクトの生成
		m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
		assert(m_pD3D);

		// プレゼンテーションパラメータの設定
		{
			D3DDISPLAYMODE disp_mode;
			m_pD3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &disp_mode);

			ZeroMemory(&m_D3DPresentParam, sizeof(D3DPRESENT_PARAMETERS));

			m_D3DPresentParam.BackBufferFormat			= disp_mode.Format;
			//m_D3DPresentParam.BackBufferWidth			= 512;
			//m_D3DPresentParam.BackBufferHeight			= static_cast<int>(512.f / GetAspect());
			m_D3DPresentParam.BackBufferCount			= 1;
			m_D3DPresentParam.SwapEffect				= D3DSWAPEFFECT_DISCARD;
			m_D3DPresentParam.EnableAutoDepthStencil	= TRUE;
			m_D3DPresentParam.AutoDepthStencilFormat	= D3DFMT_D16;
			m_D3DPresentParam.Windowed					= m_IsFullScreen ? FALSE : TRUE;
		}

		// デバイスオブジェクトの生成
		{
			HRESULT result;

			// 高度なハードウェアデバイス
			result = m_pD3D->CreateDevice(
				D3DADAPTER_DEFAULT,
				D3DDEVTYPE_HAL,
				m_hwnd,
				D3DCREATE_HARDWARE_VERTEXPROCESSING,
				&m_D3DPresentParam,
				&GetGlobalInstance()->GetDeviceInformation()->pDevice
			);

			// 失敗したら
			if ( FAILED(result) )
			{
				// ソフトウェアデバイス
				result = m_pD3D->CreateDevice(
					D3DADAPTER_DEFAULT,
					D3DDEVTYPE_HAL,
					m_hwnd,
					D3DCREATE_SOFTWARE_VERTEXPROCESSING,
					&m_D3DPresentParam,
					&GetGlobalInstance()->GetDeviceInformation()->pDevice
				);

				// 失敗したら
				if ( FAILED(result) )
				{
					// ソフトウェアデバイス
					result = m_pD3D->CreateDevice(
						D3DADAPTER_DEFAULT,
						D3DDEVTYPE_REF,
						m_hwnd,
						D3DCREATE_SOFTWARE_VERTEXPROCESSING,
						&m_D3DPresentParam,
						&GetGlobalInstance()->GetDeviceInformation()->pDevice
					);

					// 失敗
					assert ( ! result );
				}
			}
		}

		// WM_PAINTを呼ばないようにする
		ValidateRect(m_hwnd, NULL);
	}

	void iRenderer::Finalize3D()
	{
		// デバイスの開放
		if ( GetGlobalInstance()->GetDeviceInformation()->pDevice )
		{
			GetGlobalInstance()->GetDeviceInformation()->pDevice->Release();
			GetGlobalInstance()->GetDeviceInformation()->pDevice = NULL;
		}
		if ( m_pD3D )
		{
			m_pD3D->Release();
			m_pD3D = NULL;
		}
	}

	float iRenderer::GetAspect()
	{
		return (m_IsWide) ? 4.f/(9.f/4.f) : 4.f/3.f;
	}

	void iRenderer::ChangeAspect(bool wide)
	{
		m_IsWide = wide;
	}

	bool iRenderer::IsWide()
	{
		return m_IsWide;
	}

	void iRenderer::Begin()
	{
		GetGlobalInstance()->GetDeviceInformation()->pDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0,0,255), 1.0f, 0);
		GetGlobalInstance()->GetDeviceInformation()->pDevice->BeginScene();
	}

	void iRenderer::End()
	{
		GetGlobalInstance()->GetDeviceInformation()->pDevice->EndScene();
		GetGlobalInstance()->GetDeviceInformation()->pDevice->Present(NULL, NULL, NULL, NULL);

		// フレームバッファを交換する(ダブルバッファリングしてるため)
		SwapFrameBuffer();
	}

	void iRenderer::SwapFrameBuffer()
	{
	}

	bool iRenderer::ProcessMessage()
	{
		MSG msg;
		if ( PeekMessage(&msg, NULL, 0, 0, PM_REMOVE ) )
		{
			if ( msg.message == WM_QUIT )
				return false;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		return true;
	}

}
