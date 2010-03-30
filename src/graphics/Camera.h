
#pragma once

#include "graphics/DeviceInformation.h"
#include "utility/Type.h"
#include "utility/AutoImpl.h"


namespace BlueCarrot
{
	namespace graphics
	{

		class Camera
			: public utility::AutoImpl
		{
		public:
			Camera();
			virtual ~Camera();

			void CreateImpl();
			void DestroyImpl();

			void Initialize(DeviceInformation * pDeviceInformation);
			void Update();

			void SetFOV(float fov);
			void SetAspect(float aspect);
			void SetEye(const utility::Vector3 & eye);
			void SetLookat(const utility::Vector3 & lookat);
			void SetUp(const utility::Vector3 & up);
			utility::Vector3 GetEye();
			utility::Vector3 GetLookat();
			utility::Vector3 GetUp();

			void MoveEye(const utility::Vector3 & amount);

			void MoveLookat(const utility::Vector3 & amount);


		private:

		};


	}
}
