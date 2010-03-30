
#pragma once


#include <windows.h>
#include <cassert>
#include <d3d9.h>
#include <d3dx9.h>

#define ASSERT(X) assert(X)
#define ASSERT_HR(hr) ASSERT(SUCCEEDED(hr))

namespace BlueCarrot
{
	extern HINSTANCE g_hMainInstance;
	extern HINSTANCE g_hPrevInstance;
	extern LPSTR g_lpszArgs;
	extern int g_nWinMode;

	int WINAPI WindowsEntryPoint(HINSTANCE hThisInst, HINSTANCE hPrevInst, LPSTR lpszArgs, int nWinMode);
}

LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
