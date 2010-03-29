
#pragma once

#include "utility/MemoryAllocator.h"

namespace application
{
	class MainApplication;
}
namespace graphics
{
	class Renderer;
	class DeviceInformation;
}
namespace network
{
	class Network;
}
namespace job
{
	class JobManager;
}
namespace utility
{
	class KeyManager;
}



class GlobalInstance
{
private:
	graphics::Renderer * m_pRenderer;
	graphics::DeviceInformation * m_pDeviceInformation; // TODO : グローバルで持つべき？
	network::Network * m_pNetwork;
	application::MainApplication * m_pApplication;
	job::JobManager * m_pJobManager;
	utility::KeyManager * m_pKeyManager;

	// アロケータ
	// [NOTE] アロケータはメンバで持つ
	utility::MemoryAllocatorMain m_MemoryAllocatorMain;
	utility::MemoryAllocatorSub m_MemoryAllocatorSub;

public:
	GlobalInstance();
	virtual ~GlobalInstance();

	graphics::Renderer * GetRenderer() { return m_pRenderer; }
	graphics::DeviceInformation * GetDeviceInformation() { return m_pDeviceInformation; }
	network::Network * GetNetwork() { return m_pNetwork; }
	application::MainApplication * GetApplication() { return m_pApplication; }
	job::JobManager * GetJobManager() { return m_pJobManager; }
	utility::KeyManager * GetKeyManager() { return m_pKeyManager; }

	utility::MemoryAllocatorMain * GetMemoryAllocatorMain() { return &m_MemoryAllocatorMain; }
	utility::MemoryAllocatorSub * GetMemoryAllocatorSub() { return &m_MemoryAllocatorSub; }


};



void CreateGlobalInstance();
void DeleteGlobalInstance();
GlobalInstance * GetGlobalInstance();
