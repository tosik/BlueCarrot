
#include "basic/GlobalInstance.h"
#include "graphics/Renderer.h"
#include "for/win/DeviceInformation.h"
#include "for/win/iTextRenderer.h"
#include "utility/MemoryAllocator.h"
#include "for/win/MainFunction.h"
#include "for/win/winFunctions.h"


namespace graphics
{
	void TextRenderer::CreateImpl()
	{
		m_pImpl = new iTextRenderer();
	}
	void TextRenderer::DestroyImpl()
	{
		delete reinterpret_cast<iTextRenderer *>(m_pImpl);
	}
	void TextRenderer::Initialize()
	{
		reinterpret_cast<iTextRenderer *>(m_pImpl)->Initialize(GetGlobalInstance()->GetDeviceInformation(), 12, 200, L"MS Gothic");
	}
	void TextRenderer::Finalize()
	{
		reinterpret_cast<iTextRenderer *>(m_pImpl)->Finalize();
	}
	void TextRenderer::Begin()
	{
		reinterpret_cast<iTextRenderer *>(m_pImpl)->Begin();
	}
	void TextRenderer::End()
	{
		reinterpret_cast<iTextRenderer *>(m_pImpl)->End();
	}
	void TextRenderer::DrawString(std::wstring text, float x, float y, utility::Color color, float scale)
	{
		reinterpret_cast<iTextRenderer *>(m_pImpl)->DrawString(text, x, y, utility::ToDXColor(color), scale);
	}


	iTextRenderer::iTextRenderer()
	{
	}

	iTextRenderer::~iTextRenderer()
	{
	}

	void iTextRenderer::Initialize(DeviceInformation * pDeviceInformation, int height, int weight, std::wstring font_name)
	{
		HRESULT hr;

		// フォントの設定
		D3DXFONT_DESC desc;
		desc.Height				= height;
		desc.Width				= 0;
		desc.Weight				= weight;
		desc.CharSet			= SHIFTJIS_CHARSET;
		desc.Italic				= FALSE;
		desc.MipLevels			= 0;
		desc.OutputPrecision	= OUT_DEFAULT_PRECIS;
		desc.Quality			= DEFAULT_QUALITY;
		desc.PitchAndFamily		= DEFAULT_PITCH | FF_DONTCARE;
		memcpy(desc.FaceName, font_name.c_str(), sizeof(char)*32);

		// フォントを生成
		hr = D3DXCreateFontIndirect(pDeviceInformation->pDevice, &desc, &m_pFont);
		ASSERT_HR( hr );

		// スプライトを生成
		hr = D3DXCreateSprite(pDeviceInformation->pDevice, &m_pSprite);
		ASSERT_HR( hr );
	}

	void iTextRenderer::Finalize()
	{
		delete m_pSprite; // TODO : これでよい？
		delete m_pFont; // TODO : これでよい？
	}

	void iTextRenderer::Begin()
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
	}

	void iTextRenderer::End()
	{
		m_pSprite->End(); 
	}

	void iTextRenderer::DrawString(std::wstring text, float x, float y, D3DCOLOR color, float scale)
	{
		RECT rect;
		rect.left = static_cast<LONG>(x);
		rect.top = static_cast<LONG>(y);
		rect.bottom = 0;
		rect.right = 0;

		HRESULT hr;
		hr = m_pFont->DrawText(m_pSprite, text.c_str(), -1, &rect, DT_NOCLIP, color);
		ASSERT_HR( hr );
	}
}
