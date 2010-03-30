
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
			// この関数は多重起動できない
			assert(g_IsCreatedJobThread);

			// スレッドを作る(スレッド終了時に自動的にデタッチされる)
			g_JobThread = CreateThread(
				NULL, // ハンドルを継承させない
				0, // スタックは既定サイズ
				(LPTHREAD_START_ROUTINE)JobThread, // スレッド関数
				NULL, // 引数は指定しない
				0, // 実行可能状態で起動する
				NULL // 識別子は取得しない
				);

			g_IsCreatedJobThread = true;
		}

		void EndJobThread()
		{
			SetDisableJobThread();
		}

	}
}
