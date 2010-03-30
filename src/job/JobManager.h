
#pragma once

#include "job/Mutex.h"
#include "job/Job.h"
#include <vector>

namespace BlueCarrot
{
	namespace job
	{
		typedef std::vector<Job*> Jobs;

		class JobManager
		{
		private:
			// åªç›èàóùíÜÇÃÉWÉáÉu
			Job * m_pRunningJob;

			Jobs m_Jobs;
			Jobs m_EndedJobs;

			Mutex m_MutexJobs;
			Mutex m_MutexEndedJobs;

		public:
			JobManager();
			virtual ~JobManager();

			void RegisterJob(Job * pJob);

			void ExecuteJobs();

			void DeleteEndedJobs();

		private:
			void PushJob(Job * pJob);
			Job * PopJob();
		};
	}
}
