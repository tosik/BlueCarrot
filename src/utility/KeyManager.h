
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

			// ‰Ÿ‚µ‚Ä‚¢‚é
			bool IsPushing(key::Key key);

			// ¡‰Ÿ‚µ‚½‚Æ‚±‚ë
			bool IsJustPushing(key::Key key);

			// ‘O‚É‰Ÿ‚µ‚Ä‚¢‚½
			bool IsPushedPrevious(key::Key key);

		private:
			bool m_PreviousStates[(int)key::End];
		};
	}
}
