
#pragma once


#include "scene/SceneBase.h"


namespace BlueCarrot
{
	class SceneRendering
		: public SceneBase
	{

	private:


	public:

		SceneRendering(SceneID scene_id);
		virtual ~SceneRendering();

		virtual void Initialize();
		virtual void Finalize();


		// ï`âÊÇçsÇ§
		void Render();

		// ÉVÅ[Éìï`âÊ
		void RenderScene();
		void CalculateCamera();
		void CalculateCulling();
		void CalculateAnimation();
		void CalculateVertex();
		void DrawScene();

		// UI ï`âÊ
		void RenderUI();
		void CalculateUI();
		void DrawUI();

		void RenderDebugInformations();
		void RenderFPS();



	private:



	};
}
