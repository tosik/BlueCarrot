
#include "SceneSample.h"
#include "SceneID.h"

#include "debug/Debug.h"
#include "basic/GlobalInstance.h"
#include "job/JobManager.h"
#include "graphics/Renderer.h"
#include "graphics/Camera.h"
#include "graphics/Light.h"
#include "utility/Common.h"
#include "utility/KeyManager.h"
#include "utility/Type.h"


SceneSample::SceneSample(SceneID scene_id)
	: SceneRendering(scene_id)
{
}

void SceneSample::Initialize()
{
	SceneRendering::Initialize();

	graphics::Renderer * renderer = GetGlobalInstance()->GetRenderer();


	// TODO : SceneEntity ������
	m_pPrinter = new entity::EntityTextPrinter("resource/master/hoge.txt");
	m_pPrinter->Load();

	m_pBall = new Ball();
	AddSceneEntity(m_pBall);

	// �J���������ݒ�
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
	delete m_pBall;

	SceneRendering::Finalize();
}

void SceneSample::Update(unsigned int elapsed_time)
{
	SceneRendering::Update(elapsed_time);

	if ( GetGlobalInstance()->GetKeyManager()->IsPushing(utility::key::Up) )
	{
		m_pBall->Move(utility::Position<float>(0, -10));
	}
	if ( GetGlobalInstance()->GetKeyManager()->IsPushing(utility::key::Down) )
	{
		m_pBall->Move(utility::Position<float>(0, 10));
	}
	if ( GetGlobalInstance()->GetKeyManager()->IsPushing(utility::key::Left) )
	{
		m_pBall->Move(utility::Position<float>(-10, 0));
	}
	if ( GetGlobalInstance()->GetKeyManager()->IsPushing(utility::key::Right) )
	{
		m_pBall->Move(utility::Position<float>(10, 0));
	}
	if ( GetGlobalInstance()->GetKeyManager()->IsPushing(utility::key::OK) )
	{
		(*m_pBall) += utility::Size<float>(3, 3);
	}
	if ( GetGlobalInstance()->GetKeyManager()->IsPushing(utility::key::Cancel) )
	{
		(*m_pBall) -= utility::Size<float>(3, 3);
	}
}

