
#pragma once

#include <d3d9.h>
#include <d3dx9.h>
#include <string>

namespace graphics
{
	class iTexture
	{
	private:
		IDirect3DTexture9 * m_pD3DTexture;

	public:
		virtual ~iTexture()
		{
			m_pD3DTexture->Release();
		}

		void iTexture::Create(std::wstring filename);
		void iTexture::CreateFromBuffer(void * buffer, unsigned int size);

		IDirect3DTexture9 * GetInner()
		{
			return m_pD3DTexture;
		}

	};
}
