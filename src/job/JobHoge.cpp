
#pragma once

#include "job/JobHoge.h"
#include "debug/Debug.h"
#include "utility/Time.h"

namespace BlueCarrot
{
	namespace job
	{
		JobHoge::JobHoge()
		{
		}

		JobHoge::~JobHoge()
		{
		}

		void JobHoge::OnExec()
		{
			DebugOut("JobHoge::OnExec\n");

			unsigned int count = 100;
			while ( count -- )
			{
				DebugOut("JobHoge::Loop\n");
				Sleep(100);
			}

			SetEnd();
		}

		void JobHoge::OnEnd()
		{
			DebugOut("JobHoge::OnEnd");
		}

	}
}
