
#pragma once

#include "EntityLoading.h"
#include "debug/Debug.h"
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
		virtual ~EntityTextPrinter()
		{
		}

		// �ǂݍ��݂������������ɌĂяo�����
		void OnLoaded()
		{
			std::string str((char *)GetBuffer(), GetSize());
			DebugOut("text : %s\n", str.c_str());
		}
	};
}
