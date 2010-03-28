
#include "SceneSample.h"

#include "debug/Debug.h"
#include "basic/GlobalInstance.h"
#include "job/JobManager.h"
#include "graphics/Renderer.h"
#include "graphics/Camera.h"
#include "graphics/Light.h"
#include "utility/Common.h"


SceneSample::SceneSample(SceneID scene_id)
: SceneRendering(scene_id)
{
}

void SceneSample::Initialize()
{
	SceneRendering::Initialize();

	graphics::Renderer * renderer = GetGlobalInstance()->GetRenderer();


	// TODO : SceneEntity ‰»‚·‚é
	m_pPrinter = new entity::EntityTextPrinter("resource/master/hoge.txt");
	m_pPrinter->Load();

	m_pSprite = new entity::SceneEntitySprite("resource/master/reversi/board.tga");
	AddSceneEntity(m_pSprite);

	// ƒJƒƒ‰‰ŠúÝ’è
	{
		graphics::Camera * camera = renderer->GetCamera();

		camera->SetEye(utility::Vector3(0.f, 1.f, -5.f));
		camera->SetLookat(utility::Vector3(0.f, 0.f, 0.f));
		camera->SetUp(utility::Vector3(0.f, 1.f, 0.f));
		camera->SetFOV(utility::DegreeToRadian(45.f));
	}
}

void SceneSample::Finalize()
{
	delete m_pPrinter;
	delete m_pSprite;

	SceneRendering::Finalize();
}

void SceneSample::Update(unsigned int elapsed_time)
{
	SceneRendering::Update(elapsed_time);
}

