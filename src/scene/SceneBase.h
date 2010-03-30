
#pragma once


#include "SceneID.h"


namespace BlueCarrot
{
	class SceneBase
	{

	private:

		SceneID m_NextSceneID;

	public:

		SceneBase(SceneID scene_id);
		virtual ~SceneBase();

		virtual void Initialize();
		virtual void Finalize();
		virtual void Update(unsigned int elapsed_time);

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
