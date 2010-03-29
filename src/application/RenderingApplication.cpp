
#include "application/RenderingApplication.h"
#include "basic/GlobalInstance.h"
#include "graphics/Renderer.h"
#include "scene/SceneRendering.h"


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

		// •`‰æ
		renderer->Begin();
		{
			// ƒV[ƒ“‚Ì•`‰æ
			static_cast<SceneRendering*>(GetNowScene())->Render();
		}
		renderer->End();
	}

}
