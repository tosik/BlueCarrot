
#pragma once

#include "debug/Debug.h"
#include "utility/MemoryAllocator.h"
#include <string>


namespace BlueCarrot
{
	namespace network
	{

		// ネットワーク
		class Network
		{
		private:


		public:
			Network();
			virtual ~Network();

			// ネットワーク接続に必要なインスタンスを生成する
			void Create();

			// ネットワークに接続する
			void Connect(std::string address, unsigned short port);

			// ポーリング
			void Update();

		};

	}
}
