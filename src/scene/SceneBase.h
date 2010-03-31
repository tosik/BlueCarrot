
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
		* SceneEntity ����
		* SceneEntity ��ǉ�����ƁA���̃V�[���ł��� SceneEntity ������(�`��Ȃ�)�����悤�ɂȂ�
		*/
		// SceneEntity ��ǉ�����
		void AddSceneEntity(entity::SceneEntity * pSceneEntity);
		// SceneEntity ����������(�������͔j������Ȃ�)
		void RemoveSceneEntity(entity::SceneEntity * pSceneEntity);
		// SceneEntity ��S�ď�������(�������͔j������Ȃ�)
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
