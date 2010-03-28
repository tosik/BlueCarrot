
#include "graphics/Light.h"
#include "for/win/DeviceInformation.h"
#include "for/win/iLight.h"


namespace graphics
{

	void Light::CreateImpl()
	{
		m_pImpl = new iLight();
	}

	void Light::DestroyImpl()
	{
		delete reinterpret_cast<iLight *>(m_pImpl);
	}

	void Light::Initialize(DeviceInformation * pDeviceInformation)
	{
		reinterpret_cast<iLight *>(m_pImpl)->Initialize(pDeviceInformation->pDevice);
	}

	void Light::Update()
	{
		reinterpret_cast<iLight *>(m_pImpl)->Update();
	}


	void iLight::Initialize(IDirect3DDevice9 * device)
	{
		m_pDevice = device;
	}

	void iLight::Update()
	{
		// クリア
		ZeroMemory( &m_Light, sizeof( D3DLIGHT9 ) );

		// 種類
		m_Light.Type = D3DLIGHT_DIRECTIONAL;

		// ディヒューズ
		m_Light.Diffuse.r = 1.0f;
		m_Light.Diffuse.g = 1.0f;
		m_Light.Diffuse.b = 1.0f;

		// ライトに方向を設定（一応正規化も同時に行う）
		D3DXVec3Normalize((D3DXVECTOR3*)&m_Light.Direction, &m_Dir);
		m_Light.Range = 1000.f;

		// ライトを有効にする
		m_pDevice->SetLight( 0, &m_Light );
		m_pDevice->LightEnable( 0, TRUE );
		m_pDevice->SetRenderState( D3DRS_LIGHTING, TRUE );
	}


}
