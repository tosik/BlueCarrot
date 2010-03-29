
#include "utility/KeyManager.h"

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
