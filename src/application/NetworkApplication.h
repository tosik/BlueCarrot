
#pragma once

#include "network/Network.h"

#include "utility/Common.h"
#include "Application.h"


namespace application
{

	// ネットワークアプリケーション用クラス
	class NetworkApplication
		: virtual public Application
	{
	private:


	protected:


	public:

		NetworkApplication();
		virtual ~NetworkApplication();

		// アプリケーションの開始・終了時に必ず呼ぶ
		void Begin();
		void End();

		// メインループ
		virtual void OnExec(unsigned int elapsed_time);


	public:


	private:



	};

}
