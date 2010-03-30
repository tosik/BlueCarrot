
#include "graphics/Camera.h"
#include "graphics/DeviceInformation.h"

namespace BlueCarrot
{
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
}
