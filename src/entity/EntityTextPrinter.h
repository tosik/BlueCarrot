
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

		// “Ç‚İ‚İ‚ªŠ®—¹‚µ‚½‚ÉŒÄ‚Ño‚³‚ê‚é
		void OnLoaded()
		{
			std::string str((char *)GetBuffer(), GetSize());
			DebugOut("text : %s\n", str.c_str());
		}
	};
}
