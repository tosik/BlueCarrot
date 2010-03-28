
#pragma once

#include "scene/SceneBase.h"
#include "scene/SceneID.h"

void EntryPoint();


// コールバック関数

// シーンを生成する
// アプリケーションからシーンの生成タイミングにコールバックされる。
// 生成すべきシーンを示した scene_id にしたがって、シーンを生成する。
SceneBase * CreateScene(int scene_id);

// アプリケーション開始時のシーンをシーンID を指定返す関数
// アプリケーション開始時にコールバックされる
SceneID GetStartupSceneID();

