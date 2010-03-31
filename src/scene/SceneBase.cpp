
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
		// 各々の SceneEntity を更新する

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
		assert ( pos == m_SceneEntityList.end() ); // 以前に同じものを登録していないか？

		m_SceneEntityList.push_back(pSceneEntity);

		// 読み込みを開始する
		pSceneEntity->Load();
	}

	void SceneBase::RemoveSceneEntity(entity::SceneEntity * pSceneEntity)
	{
		SceneEntityList::iterator pos = std::find(m_SceneEntityList.begin(), m_SceneEntityList.end(), pSceneEntity);
		assert ( pos != m_SceneEntityList.end() ); // 存在しないものを削除しようとしていないか？
		m_SceneEntityList.erase(pos);

		// [TODO] 読み込みをキャンセルする
	}

	void SceneBase::ClearAllSceneEntity()
	{
		m_SceneEntityList.clear();
	}
}
