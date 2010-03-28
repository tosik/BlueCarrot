
#pragma once

// Ž©“®“I‚ÉŽÀ‘•‚·‚é
// usage:
/*
class iHoge;
class Hoge
	: utility::AutoImpl<iHoge>
{
	void CreateImpl();
};
---
void iHoge::CreateImpl()
{
	m_pImpl = new iHoge();
}
*/

namespace utility
{
	class AutoImpl
	{
	protected:
		void * m_pImpl;

		virtual void CreateImpl() = 0;
		virtual void DestroyImpl() = 0;
	};
}
