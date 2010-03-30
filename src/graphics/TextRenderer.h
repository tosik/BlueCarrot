
#pragma once

#include <string>
#include <utility/Type.h>
#include <utility/AutoImpl.h>


namespace BlueCarrot
{
	namespace graphics
	{
		class TextRenderer
			: public utility::AutoImpl
		{

		public:
			TextRenderer();
			virtual ~TextRenderer();
			void CreateImpl();
			void DestroyImpl();

			void Initialize();
			void Finalize();

			void Begin();
			void End();

			void DrawString(std::wstring text, float x, float y, utility::Color color, float scale);
		};
	}
}
