
#pragma once

namespace utility
{

	void WC2MB(char * mb, const wchar_t * wc);

	inline unsigned int Alignment(unsigned int i, unsigned int a)
	{
		return ( i / a + a - 1 ) * a;
	}

	inline float DegreeToRadian(float degree)
	{
		return ((degree) * (3.14159265358979f / 180.0f));
	}

}

