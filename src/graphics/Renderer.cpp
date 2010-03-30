
#include "graphics/Renderer.h"
#include "basic/GlobalInstance.h"
#include "basic/Main.h"

namespace BlueCarrot
{
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
			SetScreenSize(callback::GetScreenSize());
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

		void Renderer::DrawRect(utility::Rect<float> &rect, utility::UV &uv, utility::Color color, Texture * pTexture, bool is_enable_alphatest, bool is_enable_alphablending)
		{
			GetSprite()->Set(rect, uv, color, is_enable_alphatest, is_enable_alphablending);
			GetSprite()->SetTexture(pTexture);
			GetSprite()->Draw();
		}

	}
}
