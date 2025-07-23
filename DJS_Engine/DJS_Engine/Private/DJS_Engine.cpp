#include "DJS_Engine.h"
#include  "GLFW/glfw3.h"
#include <iostream>

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

	engineContext.windowManager = &windowManager;
	engineContext.inputManager = &inputManager;
}

void DJS_ENGINE::Run()
{
	while (shouldRun && !glfwWindowShouldClose(windowManager.GetWindow()))
	{
		windowManager.PollEvents();
		inputManager.Update();
		windowManager.ClearBackground();
		
		if (engineContext.inputManager->IsMousePressed(MOUSE_BUTTON_LEFT))
			shouldRun = false;

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