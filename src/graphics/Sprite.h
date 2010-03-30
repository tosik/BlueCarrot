
#pragma once

#include "graphics/DeviceInformation.h"
#include "utility/Common.h"
#include "utility/AutoImpl.h"
#include "utility/Type.h"
#include "graphics/Texture.h"


namespace BlueCarrot
{
	namespace graphics
	{

		class Texture;
		class Sprite
			: public utility::AutoImpl
		{
		public:
			Sprite();
			virtual ~Sprite();

			void CreateImpl();
			void DestroyImpl();

			void Draw();

			void Initialize(DeviceInformation * pDeviceInformation);
			void Finalize();

			void Set(const utility::Rect<float> &rect, const utility::UV &uv, const utility::Color & color, bool is_enable_alphatest, bool is_enable_alphablending);

			void SetTexture(Texture * pTexture);
		};

	}
}
