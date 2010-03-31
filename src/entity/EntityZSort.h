
#pragma once

#include "entity/Entity.h"

namespace BlueCarrot
{
	namespace entity
	{
		class EntityZSort
			: public Entity
		{
			double m_Z;

		public:
			EntityZSort()
				: m_Z(0.0)
			{
			}

			void SetZ(double z)
			{
				m_Z = z;
			}
			double GetZ()
			{
				return m_Z;
			}
		};
	}

	class LessZSort
	{
	public:
		bool operator()(entity::EntityZSort * left, entity::EntityZSort * right) const
		{
			return left->GetZ() < right->GetZ();
		}
	};
}
