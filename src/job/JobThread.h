
#pragma once

namespace job
{
	// �W���u�����p�̃X���b�h
	extern "C" void * JobThread(void *);

	// �W���u�����p�̃X���b�h���J�n����
	void StartJobThread();

	// �W���u�����p�̃X���b�h���I������
	void EndJobThread();

	// �W���u�����p�̃X���b�h�̏I�����w�肷��
	void SetDisableJobThread();
}
