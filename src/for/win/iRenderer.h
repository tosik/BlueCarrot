
#pragma once

#include "graphics/Renderer.h"
#include "utility/Common.h"
#include "graphics/Texture.h"
#include <d3d9.h>
#include <d3dx9.h>

namespace BlueCarrot
{
	namespace graphics
	{
		class iRenderer
		{
			friend class Renderer;

		private:
			bool m_IsFirstFrame;

			bool m_IsWide;
			float m_Aspect;


			// Windows
		private:
			// インスタンスのハンドル
			HINSTANCE m_hInstance;

			// ウィンドウのハンドル
			HWND m_hwnd;

			// ウィンドウのスタイル
			DWORD m_WindowStyle;

			// タイトル
			std::wstring m_Title;

			// 名前
			std::wstring m_Name;

			// フルスクリーンかどうか
			bool m_IsFullScreen;

			// スクリーンのサイズ
			utility::Size<int> m_ScreenSize;


			// DirectX
		private:
			// DirectXインターフェイス
			IDirect3D9 * m_pD3D;

			// プレゼンテーションパラメータ
			D3DPRESENT_PARAMETERS m_D3DPresentParam;

		public:
			iRenderer();
			virtual ~iRenderer();

		private:
			void InitializeWindows(HINSTANCE hThisInst, int nWinMode, WNDPROC pWinProcFunction);
			void FinalizeWindows();
			void Initialize3D();
			void Finalize3D();

			float GetAspect();
			void ChangeAspect(bool is_wide);
			bool IsWide();
			bool ProcessMessage();

			void SetScreenSize(const utility::Size<int> & size)
			{
				m_ScreenSize = size;
			}

			utility::Size<int> GetScreenSize()
			{
				return m_ScreenSize;
			}

			void Begin();
			void End();
			void SwapFrameBuffer();

			Texture * CreateTexture(std::wstring filename);
			Texture * CreateTextureFromBuffer(void * buffer, unsigned int size);
		};
	}
}
