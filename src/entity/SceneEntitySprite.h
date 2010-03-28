
#pragma once

#include "entity/SceneEntity.h"
#include "graphics/Texture.h"
#include "utility/Type.h"

namespace entity
{
	class SceneEntitySprite
		: public SceneEntity
	{
	private:
		graphics::Texture * m_pTexture;
		utility::Rect<float> m_Rect;
		utility::UV m_UV;
		utility::Color m_Color;

	public:
		SceneEntitySprite(std::string filename);
		virtual ~SceneEntitySprite();

		void Draw();
		void CalculateAnimation();
		void OnLoaded();

		void SetRect(const utility::Rect<float> & rect)
		{
			m_Rect = rect;
		}
	};
}
