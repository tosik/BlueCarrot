
#include "application/MainApplication.h"
#include "basic/GlobalInstance.h"
#include "debug/Debug.h"
#include "kernel/Kernel.h"
#include "basic/Main.h"
#include <cassert>


namespace application
{

	MainApplication::MainApplication()
	{
		bool result = kernel::InitializeSystem();
		assert ( result );

		Application::SetStartScene(GetStartupSceneID());
	}

	MainApplication::~MainApplication()
	{
		bool result = kernel::FinalizeSystem();
		assert ( result );
	}

	void MainApplication::Begin()
	{
		Application::Begin();
		NetworkApplication::Begin();
		RenderingApplication::Begin();
		JobApplication::Begin();

		Application::InitializeScene();
	}

	void MainApplication::End()
	{
		Application::FinalizeScene();

		JobApplication::End();
		RenderingApplication::End();
		NetworkApplication::End();
		Application::End();
	}

	void MainApplication::OnExec(unsigned int elapsed_time)
	{
		JobApplication::OnExec(elapsed_time);
		RenderingApplication::OnExec(elapsed_time);
		NetworkApplication::OnExec(elapsed_time);
		Application::OnExec(elapsed_time);
	}

}
