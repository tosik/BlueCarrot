
#pragma once

// [TODO] #ifdef ÇégÇÌÇ»Ç¢ÇÊÇ§Ç…ïœçXÇµÇΩÇ¢

#include <cassert>
#include <cstdio>

#ifdef WIN32
#include <windows.h>
#endif

#define ASSERT(X) assert(X)

#ifdef WIN32
#define ASSERT_HR(hr) ASSERT(SUCCEEDED(hr))
#endif

#ifdef WIN32
void DebugOut( LPCWSTR pszFormat, ...);
void DebugOut( LPCSTR pszFormat, ...);
#endif

