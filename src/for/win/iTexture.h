
#pragma once

#include <d3d9.h>
#include <d3dx9.h>

namespace graphics
{
	class Texture
	{
	private:
		IDirect3DTexture9 * m_pInner;

	public:
		IDirect3DTexture9 * GetInner()
		{
			return m_pInner;
		}
		void SetInner(IDirect3DTexture9 * pInner)
		{
			m_pInner = pInner;
		}
		virtual ~Texture()
		{
			m_pInner->Release();
		}
	};
}
