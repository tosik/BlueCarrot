
#include "entity/SceneEntity.h"
#include "basic/GlobalInstance.h"

namespace entity
{
	SceneEntity::SceneEntity(std::string filename)
		: EntityLoading(filename)
	{
	}

	SceneEntity::~SceneEntity()
	{
	}
}
