
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

		// TODO : �@��ˑ��e�N�X�`���̃|�C���^���擾������@�́A����ȊO�ɂȂ��̂��H
		void * GetInner();
	};
}
