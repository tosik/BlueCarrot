
#pragma once

#include "application/JobApplication.h"
#include "application/RenderingApplication.h"
#include "application/NetworkApplication.h"
#include "network/Network.h"
#include "utility/Common.h"


namespace application
{
	class iMainApplication;

	// �A�v���P�[�V�����p�N���X
	class MainApplication
		: public JobApplication
		, public RenderingApplication
		, public NetworkApplication
	{
	private:


	protected:


	public:

		MainApplication();
		virtual ~MainApplication();

		// �A�v���P�[�V�����̊J�n�E�I�����ɕK���Ă�
		void Begin();
		void End();

		// ���C�����[�v
		virtual void OnExec(unsigned int elapsed_time);


	public:


	private:



	};

}
