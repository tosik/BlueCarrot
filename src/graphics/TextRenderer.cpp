
#include "basic/GlobalInstance.h"
#include "graphics/Renderer.h"
#include "graphics/TextRenderer.h"
#include "utility/MemoryAllocator.h"


namespace graphics
{
	TextRenderer::TextRenderer()
	{
		CreateImpl();
	}

	TextRenderer::~TextRenderer()
	{
		DestroyImpl();
	}
}
