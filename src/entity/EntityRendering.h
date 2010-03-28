
#pragma once

#include "entity/Entity.h"

namespace entity
{
	class EntityRendering
		: public Entity
	{
		bool m_IsEnableRendering;

	public:
		EntityRendering()
			: m_IsEnableRendering(false)
		{
		}
		void EnableRendering()
		{
			m_IsEnableRendering = true;
		}
		void DisableRendering()
		{
			m_IsEnableRendering = false;
		}
		bool IsEnableRendering()
		{
			return m_IsEnableRendering;
		}
		virtual void Draw() = 0;
	};
}
