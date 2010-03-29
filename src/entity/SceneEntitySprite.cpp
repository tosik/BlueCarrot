
#include "entity/SceneEntitySprite.h"
#include "basic/GlobalInstance.h"
#include "graphics/Renderer.h"
#include "graphics/Texture.h"
#include "graphics/Sprite.h"

namespace entity
{
	SceneEntitySprite::SceneEntitySprite(std::string filename)
		: SceneEntity(filename)
		, m_UV(0.f, 0.f, 1.f, 1.f)
		, m_Color(255, 255, 255, 255)
		, m_Rect(0.f, 0.f, 1.f, 1.f)
		, m_pTexture(NULL)
	{
		DisableRendering();
		DisableAnimating();
	}

	SceneEntitySprite::~SceneEntitySprite()
	{
		if ( m_pTexture )
			delete m_pTexture;
	}

	void SceneEntitySprite::OnLoaded()
	{
		m_pTexture = new graphics::Texture(GetBuffer(), GetSize());

		EnableRendering();
		EnableAnimating();
	}

	void SceneEntitySprite::Draw()
	{
		GetGlobalInstance()->GetRenderer()->DrawRect(m_Rect, m_UV, m_Color, m_pTexture);
	}

	void SceneEntitySprite::CalculateAnimation()
	{
		m_Rect.height = 100;
		m_Rect.width = 100;
	}
}
