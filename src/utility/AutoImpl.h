
#pragma once

// 自動的に実装する
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

namespace BlueCarrot
{
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
}
