
#include "winFunctions.h"
#include "utility/Type.h"

#include <stdlib.h>
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC

namespace BlueCarrot
{
	namespace utility
	{
		bool InitializeSystem()
		{
			static bool is_initialized = false;

			if ( ! is_initialized )
			{
				_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

				is_initialized = true;
			}

			return true;
		}

		bool FinalizeSystem()
		{
			return true;
		}

		Vector3 ToVector3(const D3DXVECTOR3 & vec)
		{
			return Vector3(vec.x, vec.y, vec.z);
		}

		D3DXVECTOR3 ToDXVector3(const Vector3 & vec)
		{
			return D3DXVECTOR3(vec.x, vec.y, vec.z);
		}

		D3DCOLOR ToDXColor(const utility::Color & color)
		{
			return D3DCOLOR_ARGB(color.a, color.r, color.g, color.b);
		}
	}
}
