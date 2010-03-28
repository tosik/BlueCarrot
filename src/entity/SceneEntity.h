
#pragma once

#include "entity/EntityLoading.h"
#include "entity/EntityRendering.h"
#include "entity/EntityAnimating.h"

namespace entity
{
	class SceneEntity
		: public EntityLoading
		, public EntityRendering
		, public EntityAnimating
	{
	public:
		SceneEntity(std::string filename);
		virtual ~SceneEntity();
	};
}
