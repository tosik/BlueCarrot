
#include "basic/Main.h"
#include "for/win/MainFunction.h"
#include "scene/SceneID.h"
#include "SceneSample.h"
#include "SceneID.h"

int WINAPI WinMain(HINSTANCE hThisInst, HINSTANCE hPrevInst, LPSTR lpszArgs, int nWinMode)
{
	// Windows 用のアプリケーションの場合は、この関数に引数をそのまま受け渡す
	return WindowsEntryPoint(hThisInst, hPrevInst, lpszArgs, nWinMode);
}



SceneBase * CreateScene(SceneID scene_id)
{
	switch ( scene_id )
	{
	case SCENE_ID_SAMPLE:
		return new SceneSample(scene_id);
		break;
	default:
		assert(false);
		return NULL;
	}
	return NULL;
}

SceneID GetStartupSceneID()
{
	return SCENE_ID_SAMPLE;
}

utility::Size<int> GetScreenSize()
{
	return utility::Size<int>(640, 480);
}
