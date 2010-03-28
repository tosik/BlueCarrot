
#include "Debug.h"


void DebugOut( LPCWSTR pszFormat, ...)
{
	va_list	argp;
	wchar_t pszBuf[256];
	va_start(argp, pszFormat);
	vswprintf(pszBuf, pszFormat, argp);
	va_end(argp);
	OutputDebugStringW(pszBuf);
}

void DebugOut( LPCSTR pszFormat, ...)
{
	va_list	argp;
	char pszBuf[256];
	va_start(argp, pszFormat);
	vsprintf(pszBuf, pszFormat, argp);
	va_end(argp);
	OutputDebugStringA(pszBuf);
}

