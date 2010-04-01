
#pragma once

#include "graphics/Renderer.h"
#include "utility/Common.h"
#include "graphics/Texture.h"
#include <d3d9.h>
#include <d3dx9.h>

namespace BlueCarrot
{
	namespace graphics
	{
		class iRenderer
		{
			friend class Renderer;

		private:
			bool m_IsFirstFrame;

			bool m_IsWide;
			float m_Aspect;


			// Windows
		private:
			// �C���X�^���X�̃n���h��
			HINSTANCE m_hInstance;

			// �E�B���h�E�̃n���h��
			HWND m_hwnd;

			// �E�B���h�E�̃X�^�C��
			DWORD m_WindowStyle;

			// �^�C�g��
			std::wstring m_Title;

			// ���O
			std::wstring m_Name;

			// �t���X�N���[�����ǂ���
			bool m_IsFullScreen;

			// �X�N���[���̃T�C�Y
			utility::Size<int> m_ScreenSize;


			// DirectX
		private:
			// DirectX�C���^�[�t�F�C�X
			IDirect3D9 * m_pD3D;

			// �v���[���e�[�V�����p�����[�^
			D3DPRESENT_PARAMETERS m_D3DPresentParam;

		public:
			iRenderer();
			virtual ~iRenderer();

		private:
			void InitializeWindows(HINSTANCE hThisInst, int nWinMode, WNDPROC pWinProcFunction);
			void FinalizeWindows();
			void Initialize3D();
			void Finalize3D();

			float GetAspect();
			void ChangeAspect(bool is_wide);
			bool IsWide();
			bool ProcessMessage();

			void SetScreenSize(const utility::Size<int> & size)
			{
				m_ScreenSize = size;
			}

			utility::Size<int> GetScreenSize()
			{
				return m_ScreenSize;
			}

			void Begin();
			void End();
			void SwapFrameBuffer();

			Texture * CreateTexture(std::wstring filename);
			Texture * CreateTextureFromBuffer(void * buffer, unsigned int size);
		};
	}
}
