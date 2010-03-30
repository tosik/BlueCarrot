
#pragma once

#include "utility/AutoImpl.h"
#include "utility/Type.h"
#include "graphics/DeviceInformation.h"

namespace BlueCarrot
{
	namespace graphics
	{

		class Light
			: public utility::AutoImpl
		{
		public:
			Light();
			virtual ~Light();

			void CreateImpl();
			void DestroyImpl();

			void Initialize(DeviceInformation * pDeviceInformation);
			void Update();

			void SetDir(utility::Vector3 &dir);

		private:

		};

	}
}
