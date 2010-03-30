
#include "utility/Time.h"
#include <windows.h>

namespace BlueCarrot
{
	namespace utility
	{
		unsigned int GetNowTime()
		{
			return static_cast<unsigned int>(timeGetTime());
		}

		void Sleep(unsigned int time)
		{
			::Sleep(time);
		}
	}
}
