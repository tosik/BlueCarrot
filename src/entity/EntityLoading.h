
#pragma once

#include "Entity.h"
#include <string>

namespace BlueCarrot
{
	namespace job
	{
		class JobLoading;
	}

	namespace entity
	{
		class EntityLoading
			: public Entity
		{
			friend class job::JobLoading;

		private:
			void * m_pLoadedBuffer;
			unsigned int m_LoadedSize;
			std::string m_Filename;
			job::JobLoading * m_pJobLoading;

		public:
			EntityLoading(std::string filename);
			virtual ~EntityLoading();

			// 自分自身の必要なデータを1つロード開始する
			void Load();

			// 読み込みが完了した時に呼び出される
			virtual void OnLoaded() = 0;

			bool IsLoaded()
			{
				return m_LoadedSize != 0;
			}

		private:
			// 読み込みが完了したバッファを設定する
			void SetLoadedBuffer(void * buf, unsigned int size)
			{
				m_pLoadedBuffer = buf;
				m_LoadedSize = size;
			}

		protected:
			void * GetBuffer()
			{
				return m_pLoadedBuffer;
			}
			unsigned int GetSize()
			{
				return m_LoadedSize;
			}
		};
	}
}
