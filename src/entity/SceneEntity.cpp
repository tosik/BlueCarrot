
#include "entity/SceneEntity.h"
#include "basic/GlobalInstance.h"

namespace BlueCarrot
{
	namespace entity
	{
		SceneEntity::SceneEntity(std::string filename)
			: EntityLoading(filename)
			, m_IsCulling(false)
		{
		}

		SceneEntity::~SceneEntity()
		{
		}
	}
}
