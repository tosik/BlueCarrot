
#define DIRECTINPUT_VERSION 0x0800
#include "for/win/iKeyManager.h"
#include "for/win/MainFunction.h"

namespace utility
{
	int KeyToDIKEY(key::Key key)
	{
		switch ( key )
		{
		case key::Up:
			return DIK_UP;
		case key::Down:
			return DIK_DOWN;
		case key::Left:
			return DIK_LEFT;
		case key::Right:
			return DIK_RIGHT;
		case key::OK:
			return DIK_Z;
		case key::Cancel:
			return DIK_X;
		}

		abort();
		return 0;
	}


	void KeyManager::CreateImpl()
	{
		m_pImpl = new iKeyManager();
	}

	void KeyManager::DestroyImpl()
	{
		delete m_pImpl;
	}

	void KeyManager::Update()
	{
		reinterpret_cast<iKeyManager *>(m_pImpl)->Update();
	}

	bool KeyManager::IsPushing(key::Key key)
	{
		BYTE state = reinterpret_cast<iKeyManager *>(m_pImpl)->GetKeyState(KeyToDIKEY(key));
		return ( ( state & 0x80 ) != 0 );
	}

	iKeyManager::iKeyManager()
	{
		DirectInput8Create(GetModuleHandle(NULL), DIRECTINPUT_VERSION, IID_IDirectInput8, (VOID **)&m_pDI, NULL);
		m_pDI->CreateDevice(GUID_SysKeyboard, &m_pDIDevice, NULL);
		m_pDIDevice->SetDataFormat(&c_dfDIKeyboard);
		m_pDIDevice->SetCooperativeLevel(NULL, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);
		m_pDIDevice->Acquire();
	}

	iKeyManager::~iKeyManager()
	{
		m_pDIDevice->Release();
		m_pDI->Release();
	}

	void iKeyManager::Update()
	{
		m_pDIDevice->GetDeviceState(KEYBOARD_STATE_SIZE, m_KeyboardState);
	}

	BYTE iKeyManager::GetKeyState(unsigned int index)
	{
		assert( index < KEYBOARD_STATE_SIZE );
		return m_KeyboardState[index];
	}
}
