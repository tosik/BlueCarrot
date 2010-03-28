
#pragma once

#include "Application.h"


namespace application
{

	// ジョブ管理を行うようにするアプリケーションクラス
	class JobApplication
		: virtual public Application
	{
	private:


	protected:


	public:

		JobApplication();
		virtual ~JobApplication();

		// アプリケーションの開始・終了時に必ず呼ぶ
		void Begin();
		void End();

		// メインループ
		virtual void OnExec(unsigned int elapsed_time);


	public:


	private:



	};

}
