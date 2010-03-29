
#include "graphics/Texture.h"
#include "for/win/iTexture.h"
#include "basic/GlobalInstance.h"
#include "for/win/DeviceInformation.h"


namespace graphics
{

	void Texture::CreateImpl()
	{
		m_pImpl = new iTexture();
	}

	void Texture::DestroyImpl()
	{
		delete reinterpret_cast<iTexture *>(m_pImpl);
	}

	void Texture::Create(std::wstring filename)
	{
		reinterpret_cast<iTexture *>(m_pImpl)->Create(filename);
	}

	void Texture::CreateFromBuffer(void * buffer, unsigned int size)
	{
		reinterpret_cast<iTexture *>(m_pImpl)->CreateFromBuffer(buffer, size);
	}

	void * Texture::GetInner()
	{
		return static_cast<void *>(reinterpret_cast<iTexture *>(m_pImpl)->GetInner());
	}


	void iTexture::Create(std::wstring filename)
	{
		D3DXCreateTextureFromFile(GetGlobalInstance()->GetDeviceInformation()->pDevice,
			filename.c_str(), &m_pD3DTexture);
	}

	void iTexture::CreateFromBuffer(void * buffer, unsigned int size)
	{
		D3DXCreateTextureFromFileInMemory(GetGlobalInstance()->GetDeviceInformation()->pDevice,
			buffer, size, &m_pD3DTexture);
	}


}
