
#pragma once

#include "application/JobApplication.h"
#include "application/RenderingApplication.h"
#include "application/NetworkApplication.h"
#include "network/Network.h"
#include "utility/Common.h"


namespace application
{
	class iMainApplication;

	// アプリケーション用クラス
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

		// アプリケーションの開始・終了時に必ず呼ぶ
		void Begin();
		void End();

		// メインループ
		virtual void OnExec(unsigned int elapsed_time);


	public:


	private:



	};

}
