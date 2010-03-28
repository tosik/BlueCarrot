
#include "job/JobManager.h"
#include "debug/Debug.h"

namespace job
{
	JobManager::JobManager()
		: m_pRunningJob(NULL)
	{
	}

	JobManager::~JobManager()
	{
	}

	void JobManager::RegisterJob(Job * pJob)
	{
		DebugOut("JobManager::RegisterJob\n");

		m_MutexJobs.Lock();
		{
			PushJob(pJob);
		}
		m_MutexJobs.Unlock();
	}

	void JobManager::PushJob(Job * pJob)
	{
		m_Jobs.push_back(pJob);
	}

	Job * JobManager::PopJob()
	{
		Job * pJob = NULL;
		if ( m_Jobs.size() != 0 )
		{
			pJob = m_Jobs.front();
			m_Jobs.erase(m_Jobs.begin());
		}
		return pJob;
	}

	void JobManager::ExecuteJobs()
	{
		// [NOTE] 通常は、この関数はジョブスレッドから呼ばれる

		// 処理中のジョブがなければ
		if ( ! m_pRunningJob )
		{
			// 処理するジョブを取得する
			m_MutexJobs.Lock();
			{
				m_pRunningJob = PopJob();
			}
			m_MutexJobs.Unlock();
		}

		// 処理中のジョブがあれば
		if ( m_pRunningJob )
		{
			// ジョブを処理する
			m_pRunningJob->OnExec();

			// ジョブが終了したら NULL にし、削除リストに登録する
			if ( m_pRunningJob->IsEnd() )
			{
				m_MutexEndedJobs.Lock();
				{
					m_EndedJobs.push_back(m_pRunningJob);
				}
				m_MutexEndedJobs.Unlock();

				m_pRunningJob = NULL;
			}
		}
	}

	void JobManager::DeleteEndedJobs()
	{
		m_MutexEndedJobs.Lock();
		{
			// 終了したジョブの終了処理を行い、削除する
			Jobs::iterator it = m_EndedJobs.begin();
			Jobs::iterator it_end = m_EndedJobs.end();
			for ( ; it != it_end ; it ++ )
			{
				(*it)->OnEnd();
				delete (*it);
			}

			// 全部消去
			m_EndedJobs.clear();
		}
		m_MutexEndedJobs.Unlock();
	}

}
