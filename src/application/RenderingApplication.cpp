
#include "application/RenderingApplication.h"
#include "basic/GlobalInstance.h"
#include "graphics/Renderer.h"
#include "scene/SceneRendering.h"

namespace BlueCarrot
{
	namespace application
	{

		RenderingApplication::RenderingApplication()
		{
		}

		RenderingApplication::~RenderingApplication()
		{
		}

		void RenderingApplication::Begin()
		{
			GetGlobalInstance()->GetRenderer()->Initialize();
		}

		void RenderingApplication::End()
		{
			GetGlobalInstance()->GetRenderer()->Finalize();
		}

		void RenderingApplication::OnExec(unsigned int /*elapsed_time*/)
		{
		}

		void RenderingApplication::OnRender()
		{
			graphics::Renderer * renderer = GetGlobalInstance()->GetRenderer();

			// 描画
			renderer->Begin();
			{
				// シーンの描画
				static_cast<SceneRendering*>(GetNowScene())->Render();
			}
			renderer->End();
		}

	}
}
