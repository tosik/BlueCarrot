
#include "graphics/Renderer.h"
#include "basic/GlobalInstance.h"


namespace graphics
{
	Renderer::Renderer()
	{
		CreateImpl();
	}

	Renderer::~Renderer()
	{
		DestroyImpl();
	}

	void Renderer::Initialize()
	{
		InitializeDevice();
		GetTextRenderer()->Initialize();
		GetCamera()->Initialize(GetGlobalInstance()->GetDeviceInformation());
		GetLight()->Initialize(GetGlobalInstance()->GetDeviceInformation());
		GetSprite()->Initialize(GetGlobalInstance()->GetDeviceInformation());
	}
	
	void Renderer::Finalize()
	{
		GetSprite()->Finalize();
		//GetLight()->Finalize();
		//GetCamera()->Finalize();
		GetTextRenderer()->Finalize();
		FinalizeDevice();
	}

	void Renderer::DrawRect(utility::Rect<float> &rect, utility::UV &uv, utility::Color color, Texture * pTexture)
	{
		GetSprite()->Set(rect, uv, color);
		GetSprite()->SetTexture(pTexture);
		GetSprite()->Draw();
	}

}
