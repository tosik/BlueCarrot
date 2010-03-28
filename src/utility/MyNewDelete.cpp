
#include "utility/MyNewDelete.h"
#include "utility/MemoryAllocator.h"


// �A���P�[�^
utility::MemoryAllocatorForOperationNewDelete g_Allocator;


// override default new delete operations
void * operator new ( std::size_t blocksize )
{
	return g_Allocator.Allocate(blocksize);
}

void * operator new[] ( std::size_t blocksize )
{
	return g_Allocator.Allocate(blocksize);
}

void operator delete ( void * block ) throw ()
{
	g_Allocator.Free(block);
}

void operator delete[] ( void * block ) throw ()
{
	g_Allocator.Free(block);
}
