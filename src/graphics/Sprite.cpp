
#include "graphics/Sprite.h"
#include "graphics/DeviceInformation.h"

namespace BlueCarrot
{
	namespace graphics
	{

		Sprite::Sprite()
		{
			CreateImpl();
		}

		Sprite::~Sprite()
		{
			DestroyImpl();
		}

	}
}
