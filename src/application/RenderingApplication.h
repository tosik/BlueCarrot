
#pragma once

#include "Application.h"


namespace BlueCarrot
{
	namespace application
	{

		// �`��p�A�v���P�[�V�����N���X
		class RenderingApplication
			: virtual public Application
		{
		private:


		protected:


		public:

			RenderingApplication();
			virtual ~RenderingApplication();

			// �A�v���P�[�V�����̊J�n�E�I�����ɕK���Ă�
			void Begin();
			void End();

			// ���C�����[�v
			virtual void OnExec(unsigned int elapsed_time);

			// �`��
			virtual void OnRender();


		public:


		private:



		};

	}
}
