
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

			// �������g�̕K�v�ȃf�[�^��1���[�h�J�n����
			void Load();

			// �ǂݍ��݂������������ɌĂяo�����
			virtual void OnLoaded() = 0;

			bool IsLoaded()
			{
				return m_LoadedSize != 0;
			}

		private:
			// �ǂݍ��݂����������o�b�t�@��ݒ肷��
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
