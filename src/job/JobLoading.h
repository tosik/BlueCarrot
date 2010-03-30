
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
		// �t�@�C�������[�h����W���u
		// �ǂݍ��܂ꂽ�f�[�^���L������o�b�t�@�͎����I�Ɋm�ۂ����
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
			// filename : �ǂݍ��ރt�@�C���̖��O
			// pEntityLoading : �ǂݍ��܂ꂽ�f�[�^��ݒ肷��G���e�B�e�B
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
