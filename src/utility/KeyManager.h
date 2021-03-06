
#pragma once

#include "utility/AutoImpl.h"

namespace BlueCarrot
{
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

				End
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

			// 押している
			bool IsPushing(key::Key key);

			// 今押したところ
			bool IsJustPushing(key::Key key);

			// 前に押していた
			bool IsPushedPrevious(key::Key key);

		private:
			bool m_PreviousStates[(int)key::End];
		};
	}
}
