
#include "utility/KeyManager.h"

namespace BlueCarrot
{
	namespace utility
	{
		KeyManager::KeyManager()
		{
			CreateImpl();
		}

		KeyManager::~KeyManager()
		{
			DestroyImpl();
		}
	}
}
