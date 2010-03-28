
#include "job/Mutex.h"

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
