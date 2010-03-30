
#include "entity/EntityLoading.h"
#include "basic/GlobalInstance.h"
#include "job/JobManager.h"
#include "job/JobLoading.h"

namespace BlueCarrot
{
	namespace entity
	{
		EntityLoading::EntityLoading(std::string filename)
			: m_pLoadedBuffer(NULL)
			, m_LoadedSize(0)
			, m_pJobLoading(NULL)
		{
			m_Filename = filename;
		}

		EntityLoading::~EntityLoading()
		{
			GetGlobalInstance()->GetMemoryAllocatorMain()->Free(GetBuffer());

			if ( m_pJobLoading )
				delete m_pJobLoading;
		}

		void EntityLoading::Load()
		{
			job::JobManager * pJobManager = GetGlobalInstance()->GetJobManager();

			m_pJobLoading = new job::JobLoading(m_Filename, this);
			pJobManager->RegisterJob(m_pJobLoading);
		}
	}
}
