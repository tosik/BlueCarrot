
#include "job/Mutex.h"

namespace BlueCarrot
{
	namespace job
	{
		Mutex::Mutex()
		{
			CreateImpl();
		}
		Mutex::~Mutex()
		{
			DestroyImpl();
		}
	}
}
