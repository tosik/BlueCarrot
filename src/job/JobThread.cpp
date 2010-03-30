
#include "job/JobThread.h"
#include "job/JobManager.h"
#include "job/Job.h"
#include "basic/GlobalInstance.h"

namespace BlueCarrot
{
	namespace job
	{
		volatile bool g_IsEnable;

		void SetDisableJobThread()
		{
			g_IsEnable = false;
		}

		void * JobThread(void *)
		{
			g_IsEnable = true;
			while ( g_IsEnable )
			{
				JobManager * pJobManager = GetGlobalInstance()->GetJobManager();
				pJobManager->ExecuteJobs();
			}

			return NULL;
		}
	}
}
