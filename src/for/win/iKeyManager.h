
#pragma once

#include "utility/KeyManager.h"

#include <dinput.h>

namespace BlueCarrot
{
	namespace utility
	{
		static const int KEYBOARD_STATE_SIZE = 256;
		class iKeyManager
		{
		private:
			IDirectInputDevice8 * m_pDIDevice;
			IDirectInput8 * m_pDI;
			BYTE m_KeyboardState[KEYBOARD_STATE_SIZE];

		public:
			iKeyManager();
			virtual ~iKeyManager();

			void Update();
			BYTE GetKeyState(unsigned int index);

		};
	}
}
