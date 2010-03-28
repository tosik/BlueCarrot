
#pragma once

#include "job/Job.h"

namespace job
{
	class JobHoge
		: public Job
	{
	private:

	public:
		JobHoge();
		virtual ~JobHoge();

	private:
		void OnExec();
		void OnEnd();
	};
}
