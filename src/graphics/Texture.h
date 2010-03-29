
#pragma once

#include "utility/AutoImpl.h"
#include <string>

namespace graphics
{
	class Texture
		: public utility::AutoImpl
	{
	public:
		Texture(std::wstring filename);
		Texture(void * buffer, unsigned int size);
		virtual ~Texture();

		void CreateImpl();
		void DestroyImpl();

		void Create(std::wstring filename);
		void CreateFromBuffer(void * buffer, unsigned int size);

		// TODO : 機種依存テクスチャのポインタを取得する方法は、これ以外にないのか？
		void * GetInner();
	};
}
