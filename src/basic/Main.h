
#pragma once

#include "scene/SceneBase.h"
#include "scene/SceneID.h"

void EntryPoint();


// �R�[���o�b�N�֐�

// �V�[���𐶐�����
// �A�v���P�[�V��������V�[���̐����^�C�~���O�ɃR�[���o�b�N�����B
// �������ׂ��V�[���������� scene_id �ɂ��������āA�V�[���𐶐�����B
SceneBase * CreateScene(int scene_id);

// �A�v���P�[�V�����J�n���̃V�[�����V�[��ID ���w��Ԃ��֐�
// �A�v���P�[�V�����J�n���ɃR�[���o�b�N�����
SceneID GetStartupSceneID();

