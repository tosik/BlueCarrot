
#include "application/MainApplication.h"
#include "basic/GlobalInstance.h"
#include "graphics/Renderer.h"
#include "utility/Time.h"


// 時刻
unsigned int g_Time;


// エントリーポイント
void EntryPoint()
{
	CreateGlobalInstance();

	// アプリケーションへのポインタ
	application::MainApplication * pApp = GetGlobalInstance()->GetApplication();

	// 時刻を記憶する
	g_Time = utility::GetNowTime();


	// アプリケーション開始
	{
		pApp->Begin();

		// メインループ
		for ( ; ; )
		{

			// 本フレームの開始時刻
			unsigned int time = utility::GetNowTime();

			graphics::Renderer * renderer = GetGlobalInstance()->GetRenderer();
			bool result = renderer->ProcessMessage();
			if ( ! result )
				break;

			// 更新(前フレームとの時刻の差分を与える)
			pApp->OnExec(time - g_Time);

			// 描画
			pApp->OnRender();

			// フレームレートを調整する
			{
				// 本フレームの開始時刻と、現在の時刻の差が 16ms を超えるまで何もしない
				while ( utility::GetNowTime() - time < 16 )
				{
					// 何もしない
					utility::Sleep(1);
				}
			}

			// 時刻を記憶する
			g_Time = time;

		}

		// 終了
		pApp->End();
	}

	DeleteGlobalInstance();

}
