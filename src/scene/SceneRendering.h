
#pragma once


#include "scene/SceneBase.h"
#include "entity/SceneEntity.h"
#include <vector>


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
	 * SceneEntity 操作
	 * SceneEntity を追加すると、このシーンでその SceneEntity が処理(描画など)されるようになる
     */
	// SceneEntity を追加する
	void AddSceneEntity(entity::SceneEntity * pSceneEntity);
	// SceneEntity を除去する(メモリは破棄されない)
	void RemoveSceneEntity(entity::SceneEntity * pSceneEntity);
	// SceneEntity を全て除去する(メモリは破棄されない)
	void ClearAllSceneEntity();

	// 描画を行う
	void Render();

	// シーン描画
	void RenderScene();
	void CalculateCamera();
	void CalculateCulling();
	void CalculateAnimation();
	void CalculateVertex();
	void DrawScene();

	// UI 描画
	void RenderUI();
	void CalculateUI();
	void DrawUI();

	void RenderDebugInformations();
	void RenderFPS();



private:



};
