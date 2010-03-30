
#pragma once

#include "Application.h"


namespace BlueCarrot
{
	namespace application
	{

		// 描画用アプリケーションクラス
		class RenderingApplication
			: virtual public Application
		{
		private:


		protected:


		public:

			RenderingApplication();
			virtual ~RenderingApplication();

			// アプリケーションの開始・終了時に必ず呼ぶ
			void Begin();
			void End();

			// メインループ
			virtual void OnExec(unsigned int elapsed_time);

			// 描画
			virtual void OnRender();


		public:


		private:



		};

	}
}
