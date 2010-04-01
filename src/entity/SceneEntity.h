
#pragma once

#include "entity/EntityLoading.h"
#include "entity/EntityRendering.h"
#include "entity/EntityUpdating.h"
#include "entity/EntityAnimating.h"
#include "entity/EntityZSort.h"
#include "utility/Type.h"

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

			virtual bool CanCull(const utility::Rect<float> & screen)
			{
				return false;
			}
			void SetCulling(bool enable)
			{
				m_IsCulling = enable;
			}
			bool IsCulling()
			{
				return m_IsCulling;
			}

		private:
			bool m_IsCulling;
		};
	}
}
