
#pragma once

#include <windows.h>
#include <cassert>
#include <d3d9.h>
#include <d3dx9.h>

#include "graphics/DeviceInformation.h"


namespace BlueCarrot
{
	namespace graphics
	{
		// 描画に関するデバイスの情報
		class DeviceInformation
		{
		public:
			IDirect3DDevice9 * pDevice;
		};
	}
}
