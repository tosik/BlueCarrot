
#include "graphics/Texture.h"


namespace graphics
{

	Texture::Texture(std::wstring filename)
	{
		CreateImpl();
		Create(filename);
	}

	Texture::Texture(void * buffer, unsigned int size)
	{
		CreateImpl();
		CreateFromBuffer(buffer, size);
	}

	Texture::~Texture()
	{
		DestroyImpl();
	}


}
