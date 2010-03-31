
#pragma once


#include "SceneID.h"
#include "entity/SceneEntity.h"
#include <vector>


namespace BlueCarrot
{
	class SceneBase
	{

	private:

		SceneID m_NextSceneID;

	protected:
		typedef std::vector<entity::SceneEntity *> SceneEntityList;
		SceneEntityList m_SceneEntityList;

	public:

		SceneBase(SceneID scene_id);
		virtual ~SceneBase();

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


		void SetNextSceneID(SceneID scene_id)
		{
			m_NextSceneID = scene_id;
		}
		SceneID GetNextSceneID()
		{
			return m_NextSceneID;
		}


	private:



	};
}
