
#pragma once

#include <cstdio>

void * operator new ( std::size_t blocksize );
void * operator new[] ( std::size_t blocksize );
void operator delete ( void* block ) throw ();
void operator delete[] ( void* block ) throw ();
