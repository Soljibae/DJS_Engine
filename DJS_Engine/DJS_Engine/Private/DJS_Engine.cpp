#include "DJS_Engine.h"
#include  "GLFW/glfw3.h"
#include <iostream>

void DJS_ENGINE::SetEngineContext()
{
	engineContext.windowManager = &windowManager;
	engineContext.inputManager = &inputManager;
	engineContext.stateManager = &stateManager;
}

void DJS_ENGINE::Init()
{
	if (!glfwInit())
	{
		std::cerr << "Failed to Initialize glfw" << std::endl;
		return;
	}

	if(!windowManager.Init())
	{
		std::cerr << "Failed to Initialize window manager" << std::endl;
		return;
	}

	inputManager.Init(windowManager.GetWindow());

	SetEngineContext();
}

void DJS_ENGINE::Run()
{
	while (shouldRun && !glfwWindowShouldClose(windowManager.GetWindow()))
	{
		windowManager.PollEvents();
		inputManager.Update();
		windowManager.ClearBackground();
		//stateManager.Update();
		

		windowManager.SwapBuffers();
	}
}

void DJS_ENGINE::Exit()
{
	glfwTerminate();
}

EngineContext& DJS_ENGINE::GetEngineContext()
{
	return engineContext;
}