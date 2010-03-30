
#pragma once

#include "graphics/TextRenderer.h"
#include <d3d9.h>
#include <d3dx9.h>

namespace BlueCarrot
{
	namespace graphics
	{
		class iTextRenderer
		{
			friend class TextRenderer;

		private:
			ID3DXFont * m_pFont;
			ID3DXSprite * m_pSprite;

		public:
			iTextRenderer();
			virtual ~iTextRenderer();

		private:
			void Initialize(DeviceInformation * pDeviceInformation, int height, int weight, std::wstring font_name);
			void Finalize();

			void Begin();
			void End();

			void DrawString(std::wstring text, float x, float y, D3DCOLOR color, float scale);
		};
	}
}
