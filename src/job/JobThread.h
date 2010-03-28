
#pragma once

namespace job
{
	// ジョブ処理用のスレッド
	extern "C" void * JobThread(void *);

	// ジョブ処理用のスレッドを開始する
	void StartJobThread();

	// ジョブ処理用のスレッドを終了する
	void EndJobThread();

	// ジョブ処理用のスレッドの終了を指定する
	void SetDisableJobThread();
}
