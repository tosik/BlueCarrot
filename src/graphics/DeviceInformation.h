
#pragma once



namespace graphics
{
	// 描画に関するデバイスの情報
	class DeviceInformation;

	DeviceInformation * CreateDeviceInformation();

	void DeleteDeviceInformation(DeviceInformation * pDeviceInformation);
}
