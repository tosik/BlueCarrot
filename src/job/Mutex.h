
#pragma once

#include "utility/AutoImpl.h"

namespace job
{
	class Mutex
		: public utility::AutoImpl
	{
	public:
		Mutex();
		virtual ~Mutex();
		void CreateImpl();
		void DestroyImpl();

		void Lock();
		void Unlock();
	};
}
