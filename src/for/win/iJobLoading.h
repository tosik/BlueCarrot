
#pragma once

#include "job/Job.h"
#include "job/JobLoading.h"
#include <string>
#include <fstream>


namespace BlueCarrot
{
	namespace job
	{
		class iJobLoading
		{
			friend class JobLoading;

		private:
			std::ifstream m_FileStream;

		public:
			iJobLoading();

			virtual ~iJobLoading();

		private:
			void Open(std::string filename);
			void Close();
			void Load(void ** buf, unsigned int & size);

		};
	}
}
