
#include "utility/MyNewDelete.h"
#include "utility/MemoryAllocator.h"

namespace BlueCarrot
{
	// アロケータ
	utility::MemoryAllocatorForOperationNewDelete g_Allocator;
}


using namespace BlueCarrot;

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
