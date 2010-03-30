
#pragma once

#include "scene/SceneBase.h"
#include "scene/SceneID.h"
#include "utility/Type.h"

void EntryPoint();


// コールバック関数

// シーンを生成する
// アプリケーションからシーンの生成タイミングにコールバックされる。
// 生成すべきシーンを示した scene_id にしたがって、シーンを生成する。
SceneBase * CreateScene(int scene_id);

// アプリケーション開始時のシーンをシーンID を指定返す関数
// アプリケーション開始時にコールバックされる
SceneID GetStartupSceneID();

// スクリーンのサイズを返す関数
// 描画初期化時にコールバックされる
utility::Size<int> GetScreenSize();
