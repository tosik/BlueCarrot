
#include "SceneSample.h"

#include "debug/Debug.h"
#include "basic/GlobalInstance.h"
#include "job/JobManager.h"
#include "entity/EntityTextPrinter.h"
#include "graphics/Renderer.h"
#include "graphics/Camera.h"
#include "graphics/Light.h"
#include "utility/Common.h"
#include "entity/SceneEntitySprite.h"


SceneSample::SceneSample(SceneID scene_id)
: SceneRendering(scene_id)
{
}

void SceneSample::Initialize()
{
	SceneRendering::Initialize();

	entity::EntityTextPrinter * printer = new entity::EntityTextPrinter("resource/master/hoge.txt");
	printer->Load();

	graphics::Renderer * renderer = GetGlobalInstance()->GetRenderer();

	// ƒJƒƒ‰‰ŠúÝ’è
	{
		graphics::Camera * camera = renderer->GetCamera();

		camera->SetEye(utility::Vector3(0.f, 1.f, -5.f));
		camera->SetLookat(utility::Vector3(0.f, 0.f, 0.f));
		camera->SetUp(utility::Vector3(0.f, 1.f, 0.f));
		camera->SetFOV(utility::DegreeToRadian(45.f));
	}

	AddSceneEntity(new entity::SceneEntitySprite("resource/master/reversi/board.tga"));
}

void SceneSample::Finalize()
{
	SceneRendering::Finalize();
}

void SceneSample::Update(unsigned int elapsed_time)
{
	SceneRendering::Update(elapsed_time);
}

