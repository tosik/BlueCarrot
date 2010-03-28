
#include "scene/SceneRendering.h"

#include "basic/GlobalInstance.h"
#include "graphics/Renderer.h"
#include "utility/Time.h"

#include <sstream>
#include <algorithm>
#include <cassert>


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

void SceneRendering::Update(unsigned int elapsed_time)
{
}

void SceneRendering::AddSceneEntity(entity::SceneEntity * pSceneEntity)
{
	SceneEntityList::iterator pos = std::find(m_SceneEntityList.begin(), m_SceneEntityList.end(), pSceneEntity);
	assert ( pos == m_SceneEntityList.end() ); // �ȑO�ɓ������̂�o�^���Ă��Ȃ����H

	m_SceneEntityList.push_back(pSceneEntity);

	// �ǂݍ��݂��J�n����
	pSceneEntity->Load();
}

void SceneRendering::RemoveSceneEntity(entity::SceneEntity * pSceneEntity)
{
	SceneEntityList::iterator pos = std::find(m_SceneEntityList.begin(), m_SceneEntityList.end(), pSceneEntity);
	assert ( pos != m_SceneEntityList.end() ); // ���݂��Ȃ����̂��폜���悤�Ƃ��Ă��Ȃ����H
	m_SceneEntityList.erase(pos);

	// [TODO] �ǂݍ��݂��L�����Z������
}

void SceneRendering::ClearAllSceneEntity()
{
	m_SceneEntityList.clear();
}

void SceneRendering::Render()
{
	// [NOTE] �`��̗�����`����


	// �V�[����`�悷��
	RenderScene();

	// UI��`�悷��
	RenderUI();

	// �f�o�b�O����`�悷��
	RenderDebugInformations();
}


void SceneRendering::RenderScene()
{
	// �J�����̌v�Z
	CalculateCamera();

	// �J�����O
	CalculateCulling();

	// �A�j���[�V�����̌v�Z
	CalculateAnimation();

	// ���_�̌v�Z
	CalculateVertex();

	// �V�[����`�悷��
	DrawScene();
}

void SceneRendering::CalculateCamera()
{
	graphics::Renderer * renderer = GetGlobalInstance()->GetRenderer();

	// �J����
	{
		graphics::Camera * camera = renderer->GetCamera();

		// �J�����̏�Ԃ��X�V
		camera->Update();
	}

	// ���C�g
	{
		graphics::Light * light = renderer->GetLight();

		// ���C�g�̏�Ԃ��X�V
		light->Update();
	}
}

void SceneRendering::CalculateCulling()
{
	// [TODO] scene entity �̈ʒu����l���ăJ�����O���A
	// scene entity �̕`��ɉe������v�Z����؍s��Ȃ��悤�ɐݒ肷��
}

void SceneRendering::CalculateAnimation()
{
	// �e�X�� SceneEntity �̃A�j���[�V�������v�Z����

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
	// �e�X�� SceneEntity �̕`����s��

	SceneEntityList::iterator it		= m_SceneEntityList.begin();
	SceneEntityList::iterator it_end	= m_SceneEntityList.end();

	for ( ; it != it_end ; it ++ )
	{
		if ( (*it)->IsEnableRendering() )
			(*it)->Draw();
	}
}


void SceneRendering::RenderUI()
{
	// UI�̌v�Z
	CalculateUI();

	// UI��`�悷��
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
	// FPS��`�悷��
	RenderFPS();
}

void SceneRendering::RenderFPS()
{
	static unsigned int prev_time = utility::GetNowTime(); // [TODO] ��ȏ�̃V�[���������ɕ`�悳��邱�Ƃ��l������Ă��Ȃ�
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
