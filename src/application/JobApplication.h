
#pragma once

#include "Application.h"


namespace application
{

	// �W���u�Ǘ����s���悤�ɂ���A�v���P�[�V�����N���X
	class JobApplication
		: virtual public Application
	{
	private:


	protected:


	public:

		JobApplication();
		virtual ~JobApplication();

		// �A�v���P�[�V�����̊J�n�E�I�����ɕK���Ă�
		void Begin();
		void End();

		// ���C�����[�v
		virtual void OnExec(unsigned int elapsed_time);


	public:


	private:



	};

}
