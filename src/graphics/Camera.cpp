
#include "graphics/Camera.h"
#include "graphics/DeviceInformation.h"

namespace graphics
{


	Camera::Camera()
	{
		CreateImpl();
	}

	Camera::~Camera()
	{
		DestroyImpl();
	}

}
