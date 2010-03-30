
#pragma once

#include "debug/Debug.h"
#include "utility/MemoryAllocator.h"
#include <string>


namespace BlueCarrot
{
	namespace network
	{

		// �l�b�g���[�N
		class Network
		{
		private:


		public:
			Network();
			virtual ~Network();

			// �l�b�g���[�N�ڑ��ɕK�v�ȃC���X�^���X�𐶐�����
			void Create();

			// �l�b�g���[�N�ɐڑ�����
			void Connect(std::string address, unsigned short port);

			// �|�[�����O
			void Update();

		};

	}
}
