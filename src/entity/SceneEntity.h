
#pragma once

#include "entity/EntityLoading.h"
#include "entity/EntityRendering.h"
#include "entity/EntityUpdating.h"
#include "entity/EntityAnimating.h"
#include "entity/EntityZSort.h"

namespace BlueCarrot
{
	namespace entity
	{
		class SceneEntity
			: public EntityLoading
			, public EntityUpdating
			, public EntityRendering
			, public EntityAnimating
			, public EntityZSort
		{
		public:
			SceneEntity(std::string filename);
			virtual ~SceneEntity();
		};
	}
}
