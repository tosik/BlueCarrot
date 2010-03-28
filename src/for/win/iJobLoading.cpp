
#pragma once

#include "for/win/iJobLoading.h"
#include "job/JobLoading.h"
#include "entity/EntityLoading.h"
#include "debug/Debug.h"
#include "utility/Common.h"

namespace job
{
	void JobLoading::Open()
	{
		reinterpret_cast<iJobLoading *>(m_pImpl)->Open(m_Filename.c_str());
	}

	void JobLoading::Close()
	{
		reinterpret_cast<iJobLoading *>(m_pImpl)->Close();
	}

	void JobLoading::OnExec()
	{
		// ロードする
		reinterpret_cast<iJobLoading *>(m_pImpl)->Load(&m_pLoadedBuf, m_LoadedSize);

		// 終了
		SetEnd();
	}

	void JobLoading::CreateImpl()
	{
		m_pImpl = new iJobLoading();
	}

	void JobLoading::DestroyImpl()
	{
		delete reinterpret_cast<iJobLoading *>(m_pImpl);
	}



	iJobLoading::iJobLoading()
	{
	}

	iJobLoading::~iJobLoading()
	{
	}

	void iJobLoading::Open(std::string filename)
	{
		m_FileStream.open(filename.c_str(), std::ios::binary | std::ios::in);
	}

	void iJobLoading::Close()
	{
		m_FileStream.close();
	}

	void iJobLoading::Load(void ** buf, unsigned int & size)
	{
		// サイズを取得
		size = static_cast<std::size_t>(m_FileStream.seekg(0, std::ios::end).tellg());
		m_FileStream.seekg(0, std::ios::beg);
		// バッファを確保
		(*buf) = new char[size];
		// 読み込む
		m_FileStream.read(reinterpret_cast<char *>(*buf), size);
	}
}
