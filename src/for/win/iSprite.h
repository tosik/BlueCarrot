
#pragma once

#include <d3d9.h>
#include <d3dx9.h>


namespace graphics
{

	//2D頂点フォーマット
	typedef struct
	{
		// 座標
		D3DXVECTOR3	position;

		// 同次座標(4x4行列で使う)
		float		rhw;

		// 頂点色
		D3DCOLOR	color, specular;

		// UV
		FLOAT		tu, tv;

	} D3DTLSprite;


	//2Dポリゴン用
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
