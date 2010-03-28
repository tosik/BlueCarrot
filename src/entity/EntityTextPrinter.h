
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

		// 読み込みが完了した時に呼び出される
		void OnLoaded()
		{
			DebugOut("text : %s\n", (char *)GetBuffer());
		}
	};
}
