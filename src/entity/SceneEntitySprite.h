
#pragma once

#include "entity/SceneEntity.h"
#include "graphics/Texture.h"
#include "utility/Type.h"

namespace BlueCarrot
{
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
			virtual void Update(unsigned int elapsed_time);

			virtual bool CanCull(const utility::Rect<float> & screen)
			{
				return ! IsIntersect(screen);
			}

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

			void SetUV(utility::UV uv)
			{
				m_UV = uv;
			}
			void SetColor(utility::Color color)
			{
				m_Color = color;
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
}
