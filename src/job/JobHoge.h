
#pragma once

#include "job/Job.h"

namespace BlueCarrot
{
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
}
