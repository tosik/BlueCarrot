
#include "../../utility/MemoryAllocator.h"
#include "winFunctions.h"
#include <cstdlib>
#include <crtdbg.h>

namespace BlueCarrot
{
	namespace utility
	{
		void * MemoryAllocatorMain::Allocate(unsigned int size)
		{
			InitializeSystem();
			return _malloc_dbg((int)size, _NORMAL_BLOCK, __FILE__, __LINE__);
		}

		void MemoryAllocatorMain::Free(void * block)
		{
			::free(block);
		}


		void * MemoryAllocatorSub::Allocate(unsigned int size)
		{
			InitializeSystem();
			return _malloc_dbg((int)size, _NORMAL_BLOCK, __FILE__, __LINE__);
		}

		void MemoryAllocatorSub::Free(void * block)
		{
			::free(block);
		}


		void * MemoryAllocatorForOperationNewDelete::Allocate(unsigned int size)
		{
			InitializeSystem();
			return _malloc_dbg((int)size, _NORMAL_BLOCK, __FILE__, __LINE__);
		}

		void MemoryAllocatorForOperationNewDelete::Free(void * block)
		{
			::free(block);
		}

		void * MemoryAllocatorForDebug::Allocate(unsigned int size)
		{
			InitializeSystem();
			return _malloc_dbg((int)size, _NORMAL_BLOCK, __FILE__, __LINE__);
		}

		void MemoryAllocatorForDebug::Free(void * block)
		{
			::free(block);
		}


	}
}
