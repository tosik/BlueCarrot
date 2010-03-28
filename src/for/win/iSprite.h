
#pragma once

#include <d3d9.h>
#include <d3dx9.h>


namespace graphics
{

	//2D���_�t�H�[�}�b�g
	typedef struct
	{
		// ���W
		D3DXVECTOR3	position;

		// �������W(4x4�s��Ŏg��)
		float		rhw;

		// ���_�F
		D3DCOLOR	color, specular;

		// UV
		FLOAT		tu, tv;

	} D3DTLSprite;


	//2D�|���S���p
	const int D3DFVF_2DVERTEX = (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_SPECULAR | D3DFVF_TEX1);


	class iSprite
	{
	private:

		IDirect3DVertexBuffer9 * m_pVB;
		IDirect3DDevice9 * m_pDevice;
		IDirect3DTexture9 * m_pTexture;


	public:

		iSprite();
		virtual ~iSprite();

		void Draw();

		void Initialize(IDirect3DDevice9 * device);
		void Finalize();

		void Set(const utility::Rect<float> &rect, const utility::UV &uv, const D3DCOLOR & color);

		void SetTexture(IDirect3DTexture9 * pTexture);

	};


}
