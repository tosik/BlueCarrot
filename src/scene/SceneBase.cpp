
#include "SceneBase.h"
#include <algorithm>
#include <cassert>

namespace BlueCarrot
{
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
		// �e�X�� SceneEntity ���X�V����

		SceneEntityList::iterator it		= m_SceneEntityList.begin();
		SceneEntityList::iterator it_end	= m_SceneEntityList.end();

		for ( ; it != it_end ; it ++ )
		{
			if ( (*it)->IsEnableUpdating() )
				(*it)->Update(elapsed_time);
		}
	}

	void SceneBase::AddSceneEntity(entity::SceneEntity * pSceneEntity)
	{
		SceneEntityList::iterator pos = std::find(m_SceneEntityList.begin(), m_SceneEntityList.end(), pSceneEntity);
		assert ( pos == m_SceneEntityList.end() ); // �ȑO�ɓ������̂�o�^���Ă��Ȃ����H

		m_SceneEntityList.push_back(pSceneEntity);

		// �ǂݍ��݂��J�n����
		pSceneEntity->Load();
	}

	void SceneBase::RemoveSceneEntity(entity::SceneEntity * pSceneEntity)
	{
		SceneEntityList::iterator pos = std::find(m_SceneEntityList.begin(), m_SceneEntityList.end(), pSceneEntity);
		assert ( pos != m_SceneEntityList.end() ); // ���݂��Ȃ����̂��폜���悤�Ƃ��Ă��Ȃ����H
		m_SceneEntityList.erase(pos);

		// [TODO] �ǂݍ��݂��L�����Z������
	}

	void SceneBase::ClearAllSceneEntity()
	{
		m_SceneEntityList.clear();
	}
}
