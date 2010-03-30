
#include "JobApplication.h"
#include "job/JobThread.h"
#include "basic/GlobalInstance.h"
#include "job/JobManager.h"

namespace BlueCarrot
{
	namespace application
	{

		JobApplication::JobApplication()
		{
		}

		JobApplication::~JobApplication()
		{
		}

		void JobApplication::Begin()
		{
			job::StartJobThread();
		}

		void JobApplication::End()
		{
			job::EndJobThread();
		}

		void JobApplication::OnExec(unsigned int /*elapsed_time*/)
		{
			job::JobManager * pJobManager = GetGlobalInstance()->GetJobManager();

			pJobManager->DeleteEndedJobs();
		}

	}
}
