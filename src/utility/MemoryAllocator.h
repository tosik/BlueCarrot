
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
		* �e�p�r�ʃ������A���P�[�^�́A���f���p�A�e�N�X�`���p�AUI�p�A32�o�C�g�ȉ��p�ȂǂƁA
		* ���ꂼ��̃V�[���ɍ��킹�ėp�ӂ���ׂ��B
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
