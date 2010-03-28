
#include "SceneBase.h"


SceneBase::SceneBase(SceneID scene_id)
: m_NextSceneID(scene_id)
{
}

SceneBase::~SceneBase()
{
}

void SceneBase::Initialize()
{
}

void SceneBase::Finalize()
{
}

void SceneBase::Update(unsigned int elapsed_time)
{
}

