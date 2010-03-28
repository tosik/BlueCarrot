
#pragma once


#include "SceneID.h"


class SceneBase
{

private:

	SCENE_ID m_NextSceneID;

public:

	SceneBase(SCENE_ID scene_id);
	virtual ~SceneBase();

	virtual void Initialize();
	virtual void Finalize();
	virtual void Update(unsigned int elapsed_time);

	void SetNextSceneID(SCENE_ID scene_id)
	{
		m_NextSceneID = scene_id;
	}
	SCENE_ID GetNextSceneID()
	{
		return m_NextSceneID;
	}


private:



};
