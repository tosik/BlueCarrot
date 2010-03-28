
#include "graphics/Camera.h"
#include "for/win/iCamera.h"
#include "for/win/DeviceInformation.h"
#include "for/win/winFunctions.h"

namespace graphics
{

	void Camera::CreateImpl()
	{
		m_pImpl = new iCamera();
	}
	void Camera::DestroyImpl()
	{
		delete reinterpret_cast<iCamera *>(m_pImpl);
	}

	void Camera::Initialize(DeviceInformation * pDeviceInformation)
	{
		reinterpret_cast<iCamera *>(m_pImpl)->Initialize(pDeviceInformation->pDevice);
	}

	void Camera::Update()
	{
		reinterpret_cast<iCamera *>(m_pImpl)->Update();
	}

	void Camera::SetFOV(float fov)
	{
		reinterpret_cast<iCamera *>(m_pImpl)->SetFOV(fov);
	}

	void Camera::SetAspect(float aspect)
	{
		reinterpret_cast<iCamera *>(m_pImpl)->SetAspect(aspect);
	}

	void Camera::SetEye(const utility::Vector3 & eye)
	{
		reinterpret_cast<iCamera *>(m_pImpl)->SetEye(utility::ToDXVector3(eye));
	}

	void Camera::SetLookat(const utility::Vector3 & lookat)
	{
		reinterpret_cast<iCamera *>(m_pImpl)->SetLookat(utility::ToDXVector3(lookat));
	}

	void Camera::SetUp(const utility::Vector3 & up)
	{
		reinterpret_cast<iCamera *>(m_pImpl)->SetUp(utility::ToDXVector3(up));
	}

	utility::Vector3 Camera::GetEye()
	{
		return utility::ToVector3(reinterpret_cast<iCamera *>(m_pImpl)->GetEye());
	}

	utility::Vector3 Camera::GetLookat()
	{
		return utility::ToVector3(reinterpret_cast<iCamera *>(m_pImpl)->GetLookat());
	}

	utility::Vector3 Camera::GetUp()
	{
		return utility::ToVector3(reinterpret_cast<iCamera *>(m_pImpl)->GetUp());
	}


	iCamera::iCamera()
	{
		m_Eye		= D3DXVECTOR3(0.f, 0.f, 0.f);
		m_Lookat	= D3DXVECTOR3(0.f, 0.f, 0.f);
		m_Up		= D3DXVECTOR3(0.f, 1.f, 0.f);
		m_FOV		= D3DX_PI / 4.f;
		m_Aspect	= 640.f / 480.f;
	}

	iCamera::~iCamera()
	{
	}

	void iCamera::Initialize(IDirect3DDevice9 * device)
	{
		m_pDevice = device;
	}

	void iCamera::Update()
	{
		// ビュー行列を設定
		D3DXMatrixLookAtLH(&m_View, &m_Eye, &m_Lookat, &m_Up);
		m_pDevice->SetTransform(D3DTS_VIEW, &m_View);

		// プロジェクションの設定
    	D3DXMatrixPerspectiveFovLH(&m_Projection, m_FOV, m_Aspect, 1.0f, 1000.0f);
    	m_pDevice->SetTransform(D3DTS_PROJECTION, &m_Projection);

		// ビューポートの設定
		D3DVIEWPORT9 vp;
		vp.X = 0;
		vp.Y = 0;
		vp.Width = 640;
		vp.Height = 480;
		vp.MinZ = 0.f;
		vp.MaxZ = 1.f;
		m_pDevice->SetViewport(&vp);
	}

}
