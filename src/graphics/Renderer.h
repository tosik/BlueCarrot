
#pragma once

#include "graphics/TextRenderer.h"
#include "graphics/Camera.h"
#include "graphics/Light.h"
#include "graphics/Sprite.h"
#include "utility/AutoImpl.h"


namespace graphics
{
	class Renderer
		: public utility::AutoImpl
	{
	private:
		TextRenderer m_TextRenderer;
		Camera m_Camera;
		Light m_Light;
		Sprite m_Sprite;

	public:
		Renderer();
		virtual ~Renderer();

		void CreateImpl();
		void DestroyImpl();

		void Initialize();
		void Finalize();

		void InitializeDevice();
		void FinalizeDevice();

		float GetAspect();
		void ChangeAspect(bool is_wide);
		bool IsWide();
		// メッセージを処理する。false が帰ってきたら終了処理をする必要がある。
		bool ProcessMessage();

		void Begin();
		void End();

		void DrawRect(utility::Rect<float> &rect, utility::UV &uv, utility::Color color, Texture * pTexture, bool is_enable_alphatest, bool is_enable_alphablending);

		TextRenderer * GetTextRenderer()
		{
			return &m_TextRenderer;
		}

		Camera * GetCamera()
		{
			return &m_Camera;
		}

		Light * GetLight()
		{
			return &m_Light;
		}

		Sprite * GetSprite()
		{
			return &m_Sprite;
		}

		void SetScreenSize(const utility::Size<int> & size);
	};
}
