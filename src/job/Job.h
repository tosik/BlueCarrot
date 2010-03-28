
#pragma once

namespace job
{
	class JobManager;

	class Job
	{
		friend class JobManager;

	private:
		bool m_IsEnd;

	public:
		Job();
		virtual ~Job();

	protected:
		// �W���u���I���������Ƃɂ���
		void SetEnd()
		{
			m_IsEnd = true;
		}

	private:
		// �W���u���I���������ǂ���
		bool IsEnd()
		{
			return m_IsEnd;
		}

	private:
		// �W���u�̎��s���ɌĂ΂��
		// override : �W���u�̎d�����`���Ă�������
		virtual void OnExec() = 0;
		// �W���u�̏I�����ɌĂ΂��
		// override : �W���u�̏I�����̏������`���Ă�������
		virtual void OnEnd() = 0;
	};
}
