
#pragma once


#include "scene/SceneBase.h"
#include "entity/SceneEntity.h"
#include <vector>


namespace BlueCarrot
{
	class SceneRendering
		: public SceneBase
	{

	private:

		typedef std::vector<entity::SceneEntity *> SceneEntityList;
		SceneEntityList m_SceneEntityList;


	public:

		SceneRendering(SceneID scene_id);
		virtual ~SceneRendering();

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

		// �`����s��
		void Render();

		// �V�[���`��
		void RenderScene();
		void CalculateCamera();
		void CalculateCulling();
		void CalculateAnimation();
		void CalculateVertex();
		void DrawScene();

		// UI �`��
		void RenderUI();
		void CalculateUI();
		void DrawUI();

		void RenderDebugInformations();
		void RenderFPS();



	private:



	};
}
