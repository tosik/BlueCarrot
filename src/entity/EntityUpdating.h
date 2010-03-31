
#pragma once

#include "entity/Entity.h"

namespace BlueCarrot
{
	namespace entity
	{
		class EntityUpdating
			: public Entity
		{
			bool m_IsEnableUpdating;

		public:
			EntityUpdating()
				: m_IsEnableUpdating(false)
			{
			}
			void EnableUpdating()
			{
				m_IsEnableUpdating = true;
			}
			void DisableUpdating()
			{
				m_IsEnableUpdating = false;
			}
			bool IsEnableUpdating()
			{
				return m_IsEnableUpdating;
			}
			virtual void Update(unsigned int elapsed_time) = 0;
		};
	}
}
