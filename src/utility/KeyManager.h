
#pragma once

#include "utility/AutoImpl.h"

namespace utility
{
	namespace key
	{
		enum Key
		{
			Up,
			Down,
			Left,
			Right,
			OK,
			Cancel,
		};
	}

	class KeyManager
		: public AutoImpl
	{
	public:
		KeyManager();
		virtual ~KeyManager();

		void Initialize();
		void Finalize();

		void CreateImpl();
		void DestroyImpl();

		void Update();
		bool IsPushing(key::Key key);
	};
}
