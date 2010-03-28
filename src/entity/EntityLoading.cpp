
#include "entity/EntityLoading.h"
#include "basic/GlobalInstance.h"
#include "job/JobManager.h"
#include "job/JobLoading.h"

namespace entity
{
	EntityLoading::EntityLoading(std::string filename)
		: m_pLoadedBuffer(NULL)
		, m_LoadedSize(0)
	{
		m_Filename = filename;
	}

	EntityLoading::~EntityLoading()
	{
	}

	void EntityLoading::Load()
	{
		job::JobManager * pJobManager = GetGlobalInstance()->GetJobManager();

		pJobManager->RegisterJob(new job::JobLoading(m_Filename, this));
	}
}
