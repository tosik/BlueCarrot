
#pragma once


namespace BlueCarrot
{
	namespace utility
	{
		class MemoryAllocator
		{
			int m_Count;

		public:
			MemoryAllocator()
				: m_Count(0)
			{
			}

			virtual void * Allocate(unsigned int size) = 0;
			virtual void Free(void * block) = 0;

			// counter functions
		protected:
			void CountUp()
			{
				m_Count ++;
			}
			void CountDown()
			{
				m_Count --;
			}
		public:
			int GetCount()
			{
				return m_Count;
			}
		};

		/* [TODO]
		* 各用途別メモリアロケータは、モデル用、テクスチャ用、UI用、32バイト以下用などと、
		* それぞれのシーンに合わせて用意するべき。
		*/

		class MemoryAllocatorMain
			: public MemoryAllocator
		{
		public:
			void * Allocate(unsigned int size);
			void Free(void * block);
		};

		class MemoryAllocatorSub
			: public MemoryAllocator
		{
		public:
			void * Allocate(unsigned int size);
			void Free(void * block);
		};

		class MemoryAllocatorForOperationNewDelete
			: public MemoryAllocator
		{
		public:
			void * Allocate(unsigned int size);
			void Free(void * block);
		};

		class MemoryAllocatorForDebug
			: public MemoryAllocator
		{
		public:
			void * Allocate(unsigned int size);
			void Free(void * block);
		};
	}
}
