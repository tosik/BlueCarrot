
#pragma once

#include "entity/Entity.h"

namespace BlueCarrot
{
	namespace entity
	{
		class EntityAnimating
			: public Entity
		{
			bool m_IsEnableAnimating;

		public:
			EntityAnimating()
				: m_IsEnableAnimating(false)
			{
			}
			void EnableAnimating()
			{
				m_IsEnableAnimating = true;
			}
			void DisableAnimating()
			{
				m_IsEnableAnimating = false;
			}
			bool IsEnableAnimating()
			{
				return m_IsEnableAnimating;
			}

			virtual void CalculateAnimation() = 0;
		};
	}
}
