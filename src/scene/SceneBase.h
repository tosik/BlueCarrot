
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
		* SceneEntity 操作
		* SceneEntity を追加すると、このシーンでその SceneEntity が処理(描画など)されるようになる
		*/
		// SceneEntity を追加する
		void AddSceneEntity(entity::SceneEntity * pSceneEntity);
		// SceneEntity を除去する(メモリは破棄されない)
		void RemoveSceneEntity(entity::SceneEntity * pSceneEntity);
		// SceneEntity を全て除去する(メモリは破棄されない)
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
