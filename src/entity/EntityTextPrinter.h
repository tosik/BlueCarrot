
#pragma once

#include "EntityLoading.h"
#include "debug/Debug.h"
#include <iostream>

namespace BlueCarrot
{
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

			// 読み込みが完了した時に呼び出される
			void OnLoaded()
			{
				std::string str((char *)GetBuffer(), GetSize());
				DebugOut("text : %s\n", str.c_str());
			}
		};
	}
}
