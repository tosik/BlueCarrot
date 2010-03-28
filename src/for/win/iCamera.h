
#pragma once

#include <d3d9.h>
#include <d3dx9.h>


namespace graphics
{

	class iCamera
	{
	private:
		D3DXVECTOR3 m_Eye;
		D3DXVECTOR3 m_Lookat;
		D3DXVECTOR3 m_Up;

		D3DXMATRIXA16 m_View;
		D3DXMATRIXA16 m_Projection;

		IDirect3DDevice9 * m_pDevice;

		float m_FOV;
		float m_Aspect;

	public:
		iCamera();
		virtual ~iCamera();

		void Initialize(IDirect3DDevice9 * device);
		void Update();

		void SetFOV(float fov)
		{
			m_FOV = fov;
		}
		void SetAspect(float aspect)
		{
			m_Aspect = aspect;
		}
		void SetEye(const D3DXVECTOR3 & eye)
		{
			m_Eye = eye;
		}
		void SetLookat(const D3DXVECTOR3 & lookat)
		{
			m_Lookat = lookat;
		}
		void SetUp(const D3DXVECTOR3 & up)
		{
			m_Up = up;
		}
		D3DXVECTOR3 GetEye()
		{
			return m_Eye;
		}
		D3DXVECTOR3 GetLookat()
		{
			return m_Lookat;
		}
		D3DXVECTOR3 GetUp()
		{
			return m_Up;
		}

		void MoveEye(const D3DXVECTOR3 & amount)
		{
			m_Eye += amount;
		}

		void MoveLookat(const D3DXVECTOR3 & amount)
		{
			m_Lookat += amount;
		}


	private:

	};


}
