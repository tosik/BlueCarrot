
#pragma once

#include "network/Network.h"

#include "utility/Common.h"
#include "Application.h"


namespace application
{

	// �l�b�g���[�N�A�v���P�[�V�����p�N���X
	class NetworkApplication
		: virtual public Application
	{
	private:


	protected:


	public:

		NetworkApplication();
		virtual ~NetworkApplication();

		// �A�v���P�[�V�����̊J�n�E�I�����ɕK���Ă�
		void Begin();
		void End();

		// ���C�����[�v
		virtual void OnExec(unsigned int elapsed_time);


	public:


	private:



	};

}
