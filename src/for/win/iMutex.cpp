
#include "job/Mutex.h"
#include "for/win/iMutex.h"

namespace BlueCarrot
{
	namespace job
	{
		void Mutex::Lock()
		{
			reinterpret_cast<iMutex *>(m_pImpl)->Lock();
		}
		void Mutex::Unlock()
		{
			reinterpret_cast<iMutex *>(m_pImpl)->Unlock();
		}
		void Mutex::CreateImpl()
		{
			m_pImpl = new iMutex();
		}
		void Mutex::DestroyImpl()
		{
			delete reinterpret_cast<iMutex *>(m_pImpl);
		}


		iMutex::iMutex()
		{
			m_Mutex = CreateMutex(0, FALSE, 0);
		}
		iMutex::~iMutex()
		{
			CloseHandle(m_Mutex);
		}
		void iMutex::Lock()
		{
			WaitForSingleObject(m_Mutex, INFINITE);
		}
		void iMutex::Unlock()
		{
			ReleaseMutex(m_Mutex);
		}
	}
}
