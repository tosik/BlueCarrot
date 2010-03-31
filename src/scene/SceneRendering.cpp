
#include "scene/SceneRendering.h"

#include "basic/GlobalInstance.h"
#include "graphics/Renderer.h"
#include "utility/Time.h"

#include <sstream>
#include <algorithm>
#include <cassert>

namespace BlueCarrot
{

	SceneRendering::SceneRendering(SceneID scene_id)
		: SceneBase(scene_id)
	{
	}

	SceneRendering::~SceneRendering()
	{
	}

	void SceneRendering::Initialize()
	{
	}

	void SceneRendering::Finalize()
	{
	}

	void SceneRendering::Render()
	{
		// [NOTE] 描画の流れを定義する


		// シーンを描画する
		RenderScene();

		// UIを描画する
		RenderUI();

		// デバッグ情報を描画する
		RenderDebugInformations();
	}


	void SceneRendering::RenderScene()
	{
		// カメラの計算
		CalculateCamera();

		// カリング
		CalculateCulling();

		// アニメーションの計算
		CalculateAnimation();

		// 頂点の計算
		CalculateVertex();

		// シーンを描画する
		DrawScene();
	}

	void SceneRendering::CalculateCamera()
	{
		graphics::Renderer * renderer = GetGlobalInstance()->GetRenderer();

		// カメラ
		{
			graphics::Camera * camera = renderer->GetCamera();

			// カメラの状態を更新
			camera->Update();
		}

		// ライト
		{
			graphics::Light * light = renderer->GetLight();

			// ライトの状態を更新
			light->Update();
		}
	}

	void SceneRendering::CalculateCulling()
	{
		// [TODO] scene entity の位置から考えてカリングし、
		// scene entity の描画に影響する計算を一切行わないように設定する
	}

	void SceneRendering::CalculateAnimation()
	{
		// 各々の SceneEntity のアニメーションを計算する

		SceneEntityList::iterator it		= m_SceneEntityList.begin();
		SceneEntityList::iterator it_end	= m_SceneEntityList.end();

		for ( ; it != it_end ; it ++ )
		{
			if ( (*it)->IsEnableAnimating() )
				(*it)->CalculateAnimation();
		}
	}

	void SceneRendering::CalculateVertex()
	{
	}

	void SceneRendering::DrawScene()
	{
		// 各々の SceneEntity の描画を行う

		SceneEntityList::iterator it		= m_SceneEntityList.begin();
		SceneEntityList::iterator it_end	= m_SceneEntityList.end();

		// 描画順を並び替える
		std::sort(it, it_end, LessZSort());

		for ( ; it != it_end ; it ++ )
		{
			if ( (*it)->IsEnableRendering() )
				(*it)->Draw();
		}
	}


	void SceneRendering::RenderUI()
	{
		// UIの計算
		CalculateUI();

		// UIを描画する
		DrawUI();
	}

	void SceneRendering::CalculateUI()
	{
	}

	void SceneRendering::DrawUI()
	{
	}


	void SceneRendering::RenderDebugInformations()
	{
		// FPSを描画する
		RenderFPS();
	}

	void SceneRendering::RenderFPS()
	{
		static unsigned int prev_time = utility::GetNowTime(); // [TODO] 二つ以上のシーンが同時に描画されることを考慮されていない
		unsigned int now_time = utility::GetNowTime();
		float fps = 1000.f / ( now_time - prev_time );
		prev_time = now_time;

		std::wstringstream ss;
		ss << L"FPS : " << fps;

		{
			graphics::TextRenderer * textrenderer = GetGlobalInstance()->GetRenderer()->GetTextRenderer();
			textrenderer->Begin();
			textrenderer->DrawString(ss.str(), 0, 0, utility::Color(0xff,0xff,0xff,0xff), 1.0f);
			textrenderer->End();
		}
	}

}
