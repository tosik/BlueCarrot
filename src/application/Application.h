
#pragma once

#include "scene/SceneBase.h"
#include "scene/SceneID.h"


namespace application
{

	class Application
	{

	private:

		// 現在のシーン
		SceneBase * m_pNowScene;

		// シーンID
		SCENE_ID m_SceneID;
		SCENE_ID m_PrevSceneID;


	public:


		Application();
		virtual ~Application();

		// アプリケーションの開始・終了時に必ず呼ぶ
		virtual void Begin();
		virtual void End();

		void InitializeScene();
		void FinalizeScene();

		// メインループ
		virtual void OnExec(unsigned int elapsed_time);


		// 開始シーンを設定する
		void SetStartScene(SCENE_ID scene_id);

		// シーンを変更する
		// 次のフレームでシーンが変更されます
		void SwitchScene(SCENE_ID scene_id);

		// シーンを生成する
		SceneBase * CreateScene(SCENE_ID scene_id);

		SceneBase * GetNowScene()
		{
			return m_pNowScene;
		}


	private:




	};


}
