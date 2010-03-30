
#pragma once


#include "scene/SceneBase.h"
#include "entity/SceneEntity.h"
#include <vector>


namespace BlueCarrot
{
	class SceneRendering
		: public SceneBase
	{

	private:

		typedef std::vector<entity::SceneEntity *> SceneEntityList;
		SceneEntityList m_SceneEntityList;


	public:

		SceneRendering(SceneID scene_id);
		virtual ~SceneRendering();

		virtual void Initialize();
		virtual void Finalize();
		virtual void Update(unsigned int elapsed_time);


		/*
		* SceneEntity ‘€ì
		* SceneEntity ‚ğ’Ç‰Á‚·‚é‚ÆA‚±‚ÌƒV[ƒ“‚Å‚»‚Ì SceneEntity ‚ªˆ—(•`‰æ‚È‚Ç)‚³‚ê‚é‚æ‚¤‚É‚È‚é
		*/
		// SceneEntity ‚ğ’Ç‰Á‚·‚é
		void AddSceneEntity(entity::SceneEntity * pSceneEntity);
		// SceneEntity ‚ğœ‹‚·‚é(ƒƒ‚ƒŠ‚Í”jŠü‚³‚ê‚È‚¢)
		void RemoveSceneEntity(entity::SceneEntity * pSceneEntity);
		// SceneEntity ‚ğ‘S‚Äœ‹‚·‚é(ƒƒ‚ƒŠ‚Í”jŠü‚³‚ê‚È‚¢)
		void ClearAllSceneEntity();

		// •`‰æ‚ğs‚¤
		void Render();

		// ƒV[ƒ“•`‰æ
		void RenderScene();
		void CalculateCamera();
		void CalculateCulling();
		void CalculateAnimation();
		void CalculateVertex();
		void DrawScene();

		// UI •`‰æ
		void RenderUI();
		void CalculateUI();
		void DrawUI();

		void RenderDebugInformations();
		void RenderFPS();



	private:



	};
}
