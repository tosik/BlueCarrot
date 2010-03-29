
#pragma once

// Ž©“®“I‚ÉŽÀ‘•‚·‚é
// usage:
/*
class Hoge
	: utility::AutoImpl
{
	void CreateImpl();
	void DestroyImpl();
};
---
void iHoge::CreateImpl()
{
	m_pImpl = new iHoge();
}
void iHoge::DestroyImpl()
{
	delete m_pImpl;
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
