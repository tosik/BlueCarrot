
#pragma once

#include "job/JobLoading.h"
#include "entity/EntityLoading.h"
#include "debug/Debug.h"
#include "utility/Common.h"
#include <iostream>

namespace BlueCarrot
{
	namespace job
	{
		JobLoading::JobLoading(std::string filename, entity::EntityLoading * pEntityLoading)
		{
			CreateImpl();

			m_Filename = filename;
			m_pLoadedBuf = NULL;
			m_LoadedSize = 0;
			m_pEntityLoading = pEntityLoading;

			Open();
		}

		JobLoading::~JobLoading()
		{
			Close();

			DestroyImpl();
		}


		void JobLoading::OnEnd()
		{
			m_pEntityLoading->SetLoadedBuffer(m_pLoadedBuf, m_LoadedSize);
			m_pEntityLoading->OnLoaded();

			DebugOut("JobLoading::OnEnd\n");
		}
	}
}
