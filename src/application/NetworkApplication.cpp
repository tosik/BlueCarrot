
#include "NetworkApplication.h"
#include "basic/GlobalInstance.h"

namespace BlueCarrot
{
	namespace application
	{

		NetworkApplication::NetworkApplication()
		{
		}

		NetworkApplication::~NetworkApplication()
		{
		}

		void NetworkApplication::Begin()
		{
		}

		void NetworkApplication::End()
		{
		}

		void NetworkApplication::OnExec(unsigned int elapsed_time)
		{
			GetGlobalInstance()->GetNetwork()->Update();
		}

	}
}
