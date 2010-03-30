
#pragma once

#include <windows.h>
#include <cassert>
#include <d3d9.h>
#include <d3dx9.h>

#include "utility/Type.h"
#include "utility/Common.h"

namespace BlueCarrot
{
	namespace utility
	{
		bool InitializeSystem();
		bool FinalizeSystem();

		Vector3 ToVector3(const D3DXVECTOR3 & vec);
		D3DXVECTOR3 ToDXVector3(const Vector3 & vec);
		D3DCOLOR ToDXColor(const utility::Color & color);
	}
}
