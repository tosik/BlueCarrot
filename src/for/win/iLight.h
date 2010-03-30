
#pragma once

#include <d3d9.h>
#include <d3dx9.h>


namespace BlueCarrot
{
	namespace graphics
	{

		class iLight
		{
		private:
			D3DXVECTOR3	m_Dir;
			D3DLIGHT9	m_Light;

			IDirect3DDevice9 * m_pDevice;

		public:
			void Initialize(IDirect3DDevice9 * device);
			void Update();

			void SetDir(D3DXVECTOR3 &dir)
			{
				m_Dir = dir;
			}

		private:

		};

	}
}
