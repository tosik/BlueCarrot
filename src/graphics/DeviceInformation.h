
#pragma once



namespace BlueCarrot
{
	namespace graphics
	{
		// �`��Ɋւ���f�o�C�X�̏��
		class DeviceInformation;

		DeviceInformation * CreateDeviceInformation();

		void DeleteDeviceInformation(DeviceInformation * pDeviceInformation);
	}
}
