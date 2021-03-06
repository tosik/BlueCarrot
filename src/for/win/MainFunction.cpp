
#include "basic/Main.h"
#include "for/win/MainFunction.h"

#include <windows.h>

namespace BlueCarrot
{

	HINSTANCE g_hMainInstance;
	HINSTANCE g_hPrevInstance;
	LPSTR g_lpszArgs;
	int g_nWinMode;

	// Windows 用エントリーポイント
	int WINAPI WindowsEntryPoint(HINSTANCE hThisInst, HINSTANCE hPrevInst, LPSTR lpszArgs, int nWinMode)
	{
		// Windows 呼び出し時の引数を保存する
		g_hMainInstance = hThisInst;
		g_hPrevInstance = hPrevInst;
		g_lpszArgs = lpszArgs;
		g_nWinMode = nWinMode;

		EntryPoint();

		return 0;
	}
}

LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch ( message )
	{
	case WM_KEYDOWN:
//		GetNowScene()->OnKeyDown(wParam);
		switch ( wParam )
		{
		case VK_ESCAPE:
			PostMessage(hWnd, WM_CLOSE, 0, 0);
			break;
		}
		break;

	case WM_KEYUP:
//		GetNowScene()->OnKeyUp(wParam);
		break;

	case WM_LBUTTONDOWN:
//		GetNowScene()->OnClick(wParam, lParam);
		break;

	case WM_SETCURSOR:
		//// カーソルはなし
		//SetCursor(NULL);
		break;

	case WM_PAINT:
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}
