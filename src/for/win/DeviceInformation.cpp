
#include <windows.h>
#include <cassert>
#include <d3d9.h>
#include <d3dx9.h>
#include "graphics/DeviceInformation.h"
#include "for/win/DeviceInformation.h"

namespace BlueCarrot
{
	namespace graphics
	{
		DeviceInformation * CreateDeviceInformation()
		{
			return new DeviceInformation;
		}

		void DeleteDeviceInformation(DeviceInformation * pDeviceInformation)
		{
			delete pDeviceInformation;
		}
	}
}
