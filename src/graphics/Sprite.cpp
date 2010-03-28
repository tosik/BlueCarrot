
#include "graphics/Sprite.h"
#include "graphics/DeviceInformation.h"

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
