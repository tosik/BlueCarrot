
#include "Application.h"
#include "debug/Debug.h"
#include "utility/Common.h"
#include "basic/Main.h"
#include <cassert>

namespace BlueCarrot
{
	namespace application
	{

		Application::Application()
		{
		}

		Application::~Application()
		{
		}

		void Application::Begin()
		{
			m_pNowScene = CreateScene(m_SceneID);
		}

		void Application::End()
		{
			delete m_pNowScene;
		}

		void Application::InitializeScene()
		{
			m_pNowScene->Initialize();
		}

		void Application::FinalizeScene()
		{
			m_pNowScene->Finalize();
		}

		void Application::SetStartScene(int scene_id)
		{
			m_SceneID = scene_id;
			m_PrevSceneID = m_SceneID;
		}

		void Application::SwitchScene(int scene_id)
		{
			m_pNowScene->SetNextSceneID(scene_id);
			m_SceneID = scene_id;
		}

		void Application::OnExec(unsigned int elapsed_time)
		{
			// シーンが変更されていたら
			m_SceneID = m_pNowScene->GetNextSceneID();
			if ( m_SceneID != m_PrevSceneID )
			{
				// 今のシーンを終了する
				m_pNowScene->Finalize();
				delete m_pNowScene;

				// 次のシーンを作る
				m_pNowScene = CreateScene(m_SceneID);
				m_pNowScene->Initialize();

				m_PrevSceneID = m_SceneID;
			}

			GetNowScene()->Update(elapsed_time);
		}

		SceneBase * Application::CreateScene(int scene_id)
		{
			return callback::CreateScene(scene_id);
		}

	}
}