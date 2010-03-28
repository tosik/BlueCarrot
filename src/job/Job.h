
#pragma once

namespace job
{
	class JobManager;

	class Job
	{
		friend class JobManager;

	private:
		bool m_IsEnd;

	public:
		Job();
		virtual ~Job();

	protected:
		// ジョブが終了したことにする
		void SetEnd()
		{
			m_IsEnd = true;
		}

	private:
		// ジョブが終了したかどうか
		bool IsEnd()
		{
			return m_IsEnd;
		}

	private:
		// ジョブの実行時に呼ばれる
		// override : ジョブの仕事を定義してください
		virtual void OnExec() = 0;
		// ジョブの終了時に呼ばれる
		// override : ジョブの終了時の処理を定義してください
		virtual void OnEnd() = 0;
	};
}
