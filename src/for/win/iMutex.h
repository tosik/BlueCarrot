
#pragma once

#include <windows.h>
#include <process.h>


namespace job
{
	class iMutex
	{
		friend class Mutex;

	private:
		HANDLE m_Mutex;

	public:
		iMutex();
		virtual ~iMutex();

	private:
		void Lock();
		void Unlock();
	};
}
