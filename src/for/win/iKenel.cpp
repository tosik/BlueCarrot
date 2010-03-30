
#include "kernel/Kernel.h"
#include "winFunctions.h"

namespace BlueCarrot
{
	namespace kernel
	{
		bool InitializeSystem()
		{
			return utility::InitializeSystem();
		}

		bool FinalizeSystem()
		{
			return utility::FinalizeSystem();
		}


	}
}
