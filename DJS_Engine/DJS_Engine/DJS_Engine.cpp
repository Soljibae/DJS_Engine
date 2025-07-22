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

}

void DJS_ENGINE::Run()
{
	//window

	while (shouldRun)
	{

	}


}

void DJS_ENGINE::Exit()
{

}