#define GLAD_GL_IMPLEMENTATION
#include "GLAD/gl.h"
#include "DJS_Engine.h"
#include  "GLFW/glfw3.h"
#include <iostream>

void DJS_ENGINE::SetEngineContext()
{
	engineContext.windowManager = &windowManager;
	engineContext.inputManager = &inputManager;
	engineContext.stateManager = &stateManager;
	engineContext.renderManager = &renderManager;
}

void DJS_ENGINE::Init()
{
	if (!glfwInit())
	{
		std::cerr << "Failed to Initialize glfw" << std::endl;
		return;
	}

	SetEngineContext();

	if(!windowManager.Init())
	{
		std::cerr << "Failed to Initialize window manager" << std::endl;
		return;
	}

	if (!gladLoadGL(glfwGetProcAddress)) // gladLoadGL 함수 호출
	{
		std::cerr << "Failed to initialize GLAD" << std::endl;
		return; // GLAD 초기화 실패 시 프로그램 종료
	}

	inputManager.Init(windowManager.GetWindow());
	renderManager.Init();
}

void DJS_ENGINE::Run()
{
	while (shouldRun && !glfwWindowShouldClose(windowManager.GetWindow()))
	{
		windowManager.PollEvents();
		inputManager.Update();
		windowManager.ClearBackground();
		stateManager.Update();
		stateManager.Draw();

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