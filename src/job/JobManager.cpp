
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
		// [NOTE] �ʏ�́A���̊֐��̓W���u�X���b�h����Ă΂��

		// �������̃W���u���Ȃ����
		if ( ! m_pRunningJob )
		{
			// ��������W���u���擾����
			m_MutexJobs.Lock();
			{
				m_pRunningJob = PopJob();
			}
			m_MutexJobs.Unlock();
		}

		// �������̃W���u�������
		if ( m_pRunningJob )
		{
			// �W���u����������
			m_pRunningJob->OnExec();

			// �W���u���I�������� NULL �ɂ��A�폜���X�g�ɓo�^����
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
			// �I�������W���u�̏I���������s���A�폜����
			Jobs::iterator it = m_EndedJobs.begin();
			Jobs::iterator it_end = m_EndedJobs.end();
			for ( ; it != it_end ; it ++ )
			{
				(*it)->OnEnd();
				delete (*it);
			}

			// �S������
			m_EndedJobs.clear();
		}
		m_MutexEndedJobs.Unlock();
	}

}
