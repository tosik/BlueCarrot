
#include "job/JobThread.h"
#include "job/JobManager.h"
#include "job/Job.h"
#include "basic/GlobalInstance.h"
#include <cassert>
#include <windows.h>

namespace BlueCarrot
{
	namespace job
	{
		HANDLE g_JobThread;
		static bool g_IsCreatedJobThread = true;

		void StartJobThread()
		{
			// ���̊֐��͑��d�N���ł��Ȃ�
			assert(g_IsCreatedJobThread);

			// �X���b�h�����(�X���b�h�I�����Ɏ����I�Ƀf�^�b�`�����)
			g_JobThread = CreateThread(
				NULL, // �n���h�����p�������Ȃ�
				0, // �X�^�b�N�͊���T�C�Y
				(LPTHREAD_START_ROUTINE)JobThread, // �X���b�h�֐�
				NULL, // �����͎w�肵�Ȃ�
				0, // ���s�\��ԂŋN������
				NULL // ���ʎq�͎擾���Ȃ�
				);

			g_IsCreatedJobThread = true;
		}

		void EndJobThread()
		{
			SetDisableJobThread();
		}

	}
}
