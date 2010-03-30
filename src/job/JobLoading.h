
#pragma once

#include "job/Job.h"
#include "utility/AutoImpl.h"
#include <string>


namespace BlueCarrot
{
	namespace entity
	{
		class EntityLoading;
	}

	namespace job
	{
		// ファイルをロードするジョブ
		// 読み込まれたデータを記憶するバッファは自動的に確保される
		class JobLoading
			: public Job
			, public utility::AutoImpl
		{
		private:
			std::string m_Filename;
			void * m_pLoadedBuf;
			unsigned int m_LoadedSize;
			entity::EntityLoading * m_pEntityLoading;

		public:
			// filename : 読み込むファイルの名前
			// pEntityLoading : 読み込まれたデータを設定するエンティティ
			JobLoading(std::string filename, entity::EntityLoading * pEntityLoading);
			virtual ~JobLoading();

			void CreateImpl();
			void DestroyImpl();

		private:
			void Open();
			void Close();
			void OnExec();
			void OnEnd();
		};
	}
}
