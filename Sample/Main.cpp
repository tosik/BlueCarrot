
#include "for/win/MainFunction.h"

int WINAPI WinMain(HINSTANCE hThisInst, HINSTANCE hPrevInst, LPSTR lpszArgs, int nWinMode)
{
	return WindowsEntryPoint(hThisInst, hPrevInst, lpszArgs, nWinMode);
}
