
#include "Light.h"


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
