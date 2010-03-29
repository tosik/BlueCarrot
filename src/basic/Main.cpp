
#include "application/MainApplication.h"
#include "basic/GlobalInstance.h"
#include "graphics/Renderer.h"
#include "utility/Time.h"
#include "utility/KeyManager.h"


// ����
unsigned int g_Time;


// �G���g���[�|�C���g
void EntryPoint()
{
	CreateGlobalInstance();

	// �A�v���P�[�V�����ւ̃|�C���^
	application::MainApplication * pApp = GetGlobalInstance()->GetApplication();

	// �������L������
	g_Time = utility::GetNowTime();


	// �A�v���P�[�V�����J�n
	{
		pApp->Begin();

		// ���C�����[�v
		for ( ; ; )
		{

			// �{�t���[���̊J�n����
			unsigned int time = utility::GetNowTime();

			graphics::Renderer * renderer = GetGlobalInstance()->GetRenderer();
			bool result = renderer->ProcessMessage();
			if ( ! result )
				break;

			// �L�[�{�[�h�̏�ԍX�V
			GetGlobalInstance()->GetKeyManager()->Update();

			// �X�V(�O�t���[���Ƃ̎����̍�����^����)
			pApp->OnExec(time - g_Time);

			// �`��
			pApp->OnRender();

			// �t���[�����[�g�𒲐�����
			{
				// �{�t���[���̊J�n�����ƁA���݂̎����̍��� 16ms �𒴂���܂ŉ������Ȃ�
				while ( utility::GetNowTime() - time < 16 )
				{
					// �������Ȃ�
					utility::Sleep(1);
				}
			}

			// �������L������
			g_Time = time;

		}

		// �I��
		pApp->End();
	}

	DeleteGlobalInstance();

}
