
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


		// 描画を行う
		void Render();

		// シーン描画
		void RenderScene();
		void CalculateCamera();
		void CalculateCulling();
		void CalculateAnimation();
		void CalculateVertex();
		void DrawScene();

		// UI 描画
		void RenderUI();
		void CalculateUI();
		void DrawUI();

		void RenderDebugInformations();
		void RenderFPS();



	private:



	};
}
