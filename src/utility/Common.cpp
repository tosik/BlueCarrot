
#include "Common.h"
#include <locale.h>
#include <stdlib.h>

namespace utility
{

	void WC2MB(char * mb, const wchar_t * wc)
	{
		int index = 0;
		int i = 0;
		int len = wctomb(&mb[i], wc[i]);
		while (len > 0)
		{
			index += len;
			i++;
			len = wctomb(&mb[i], wc[index]);
		}
	}

}
