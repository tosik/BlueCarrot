
#pragma once

#include "entity/SceneEntity.h"
#include "graphics/Texture.h"
#include "utility/Type.h"

namespace entity
{
	class SceneEntitySprite
		: public SceneEntity
		, public utility::Rect<float>
	{
	private:
		graphics::Texture * m_pTexture;
		utility::UV m_UV;
		utility::Color m_Color;
		bool m_IsEnableAlphatest;
		bool m_IsEnableAlphablending;

	public:
		SceneEntitySprite(std::string filename);
		virtual ~SceneEntitySprite();

		virtual void Draw();
		virtual void CalculateAnimation();
		virtual void OnLoaded();

		graphics::Texture * GetTexture()
		{
			return m_pTexture;
		}
		utility::UV GetUV()
		{
			return m_UV;
		}
		utility::Color GetColor()
		{
			return m_Color;
		}
		bool IsEnableAlphatest()
		{
			return m_IsEnableAlphatest;
		}
		bool IsEnableAlphablending()
		{
			return m_IsEnableAlphablending;
		}

		void EnableAlphatest()
		{
			m_IsEnableAlphatest = true;
		}
		void DisableAlphatest()
		{
			m_IsEnableAlphatest = false;
		}
		void EnableAlphablending()
		{
			m_IsEnableAlphablending = true;
		}
		void DisableAlphablending()
		{
			m_IsEnableAlphablending = false;
		}
	};
}
