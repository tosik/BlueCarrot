
#include "graphics/Sprite.h"
#include "for/win/iSprite.h"
#include "for/win/DeviceInformation.h"
#include "for/win/winFunctions.h"
#include "for/win/iTexture.h"
#include "debug/Debug.h"

namespace graphics
{

	void Sprite::CreateImpl()
	{
		m_pImpl = new iSprite();
	}
	void Sprite::DestroyImpl()
	{
		delete reinterpret_cast<iSprite *>(m_pImpl);
	}

	void Sprite::Initialize(DeviceInformation * pDeviceInformation)
	{
		reinterpret_cast<iSprite *>(m_pImpl)->Initialize(pDeviceInformation->pDevice);
	}

	void Sprite::Finalize()
	{
		reinterpret_cast<iSprite *>(m_pImpl)->Finalize();
	}

	void Sprite::Draw()
	{
		reinterpret_cast<iSprite *>(m_pImpl)->Draw();
	}

	void Sprite::Set(const utility::Rect<float> &rect, const utility::UV &uv, const utility::Color & color)
	{
		reinterpret_cast<iSprite *>(m_pImpl)->Set(rect, uv, ToDXColor(color));
	}

	void Sprite::SetTexture(Texture * pTexture)
	{
		reinterpret_cast<iSprite *>(m_pImpl)->SetTexture(reinterpret_cast<IDirect3DTexture9 *>(pTexture->GetInner()));
	}


	iSprite::iSprite()
	{
		m_pTexture = NULL;
	}

	iSprite::~iSprite()
	{
	}

	void iSprite::Initialize(IDirect3DDevice9 * device)
	{
		m_pDevice = device;

		HRESULT	hr = m_pDevice->CreateVertexBuffer(
			sizeof(D3DTLSprite) * 4,
			0,
			D3DFVF_2DVERTEX,
			D3DPOOL_DEFAULT,
			&m_pVB,
			NULL
		);
		ASSERT_HR( hr );
	}

	void iSprite::Finalize()
	{
		// [TODO] ‚±‚ê‚Å‚æ‚¢H
		LocalFree(m_pVB);
	}

	void iSprite::Draw()
	{
		HRESULT hr;

		if ( m_pTexture )
		{
			hr = m_pDevice->SetTexture( 0, m_pTexture );
			ASSERT_HR( hr );
		}

		hr = m_pDevice->SetStreamSource( 0, m_pVB, 0, sizeof(D3DTLSprite) );
		ASSERT_HR( hr );

		hr = m_pDevice->SetFVF( D3DFVF_2DVERTEX );
		ASSERT_HR( hr );

		hr = m_pDevice->DrawPrimitive( D3DPT_TRIANGLESTRIP, 0, 2 );
		ASSERT_HR( hr );
	}

	void iSprite::Set(const utility::Rect<float> &rect, const utility::UV &uv, const D3DCOLOR & color)
	{
		ASSERT( m_pVB );

		D3DTLSprite * v;
		HRESULT hr;

		hr = m_pVB->Lock(0, 0, (void**)&v, 0);
		ASSERT_HR( hr );


		// ¶ã
		v[0].position	= D3DXVECTOR3(rect.left, rect.top, 0.0f);
		v[0].color		= color;
		v[0].rhw		= 1.f;
		v[0].specular	= 0;
		v[0].tu			= uv.u;
		v[0].tv			= uv.v;

		// ‰Eã
		v[1].position	= D3DXVECTOR3(rect.left + rect.width, rect.top, 0.0f);
		v[1].color		= color;
		v[1].rhw		= 1.f;
		v[1].specular	= 0;
		v[1].tu			= uv.um;
		v[1].tv			= uv.v;

		// ¶‰º
		v[2].position	= D3DXVECTOR3(rect.left, rect.top + rect.height, 0.0f);
		v[2].color		= color;
		v[2].rhw		= 1.f;
		v[2].specular	= 0;
		v[2].tu			= uv.u;
		v[2].tv			= uv.vm;

		// ‰E‰º
		v[3].position	= D3DXVECTOR3(rect.left + rect.width, rect.top + rect.height, 0.0f);
		v[3].color		= color;
		v[3].rhw		= 1.f;
		v[3].specular	= 0;
		v[3].tu			= uv.um;
		v[3].tv			= uv.vm;


		hr = m_pVB->Unlock();
		ASSERT_HR( hr );
	}

	void iSprite::SetTexture(IDirect3DTexture9 * pTexture)
	{
		m_pTexture = pTexture;
	}

}
