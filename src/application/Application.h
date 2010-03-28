
#pragma once

#include "scene/SceneBase.h"
#include "scene/SceneID.h"


namespace application
{

	class Application
	{

	private:

		// ���݂̃V�[��
		SceneBase * m_pNowScene;

		// �V�[��ID
		SCENE_ID m_SceneID;
		SCENE_ID m_PrevSceneID;


	public:


		Application();
		virtual ~Application();

		// �A�v���P�[�V�����̊J�n�E�I�����ɕK���Ă�
		virtual void Begin();
		virtual void End();

		void InitializeScene();
		void FinalizeScene();

		// ���C�����[�v
		virtual void OnExec(unsigned int elapsed_time);


		// �J�n�V�[����ݒ肷��
		void SetStartScene(SCENE_ID scene_id);

		// �V�[����ύX����
		// ���̃t���[���ŃV�[�����ύX����܂�
		void SwitchScene(SCENE_ID scene_id);

		// �V�[���𐶐�����
		SceneBase * CreateScene(SCENE_ID scene_id);

		SceneBase * GetNowScene()
		{
			return m_pNowScene;
		}


	private:




	};


}
