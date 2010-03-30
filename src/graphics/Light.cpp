
#include "graphics/Light.h"

namespace BlueCarrot
{
	namespace graphics
	{

		Light::Light()
		{
			CreateImpl();
		}

		Light::~Light()
		{
			DestroyImpl();
		}


	}
}
