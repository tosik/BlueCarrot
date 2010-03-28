
#pragma once

#include "EntityLoading.h"
#include <iostream>

namespace entity
{
	class EntityTextPrinter
		: public EntityLoading
	{
	public:
		EntityTextPrinter(std::string filename)
			: EntityLoading(filename)
		{
		}
		virtual ~EntityTextPrinter() {};

		// �ǂݍ��݂������������ɌĂяo�����
		void OnLoaded()
		{
			DebugOut("text : %s\n", (char *)GetBuffer());
		}
	};
}
