
#include "GlobalInstance.h"

#include "application/MainApplication.h"
#include "graphics/Renderer.h"
#include "graphics/DeviceInformation.h"
#include "network/Network.h"
#include "utility/MemoryAllocator.h"
#include "job/JobManager.h"



GlobalInstance::GlobalInstance()
{
	m_pApplication = new application::MainApplication();
	m_pRenderer = new graphics::Renderer();
	m_pDeviceInformation = graphics::CreateDeviceInformation();
	m_pNetwork = new network::Network();
	m_pJobManager = new job::JobManager();
}

GlobalInstance::~GlobalInstance()
{
	delete m_pJobManager;
	delete m_pNetwork;
	graphics::DeleteDeviceInformation(m_pDeviceInformation);
	delete m_pRenderer;
	delete m_pApplication;
}


GlobalInstance * g_pGlobalInstance;

void CreateGlobalInstance()
{
	g_pGlobalInstance = new GlobalInstance();
}
void DeleteGlobalInstance()
{
	delete g_pGlobalInstance;
}
GlobalInstance * GetGlobalInstance()
{
	return g_pGlobalInstance;
}

