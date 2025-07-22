#include "WindowManager.h"
#include  "GLFW/glfw3.h"
#include <iostream>

bool WindowManager::Init()
{
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

	if (!window)
	{
		std::cerr << "Failed to create GLFW window" << std::endl;
		return false;
	}

	glfwMakeContextCurrent(window);

	return true;
}

void WindowManager::Exit()
{
	glfwDestroyWindow(window);
	//glfwTerminate();
}

void WindowManager::SwapBuffers()
{
	glfwSwapBuffers(window);
}

void WindowManager::SetWindowSize(float width, float height)
{
	this->width = width;
	this->height = height;
}

void WindowManager::SetWindowTitle(std::string title)
{
	this->title = title;
}

void WindowManager::SetWindowIcon()
{
	//to do: need stb_image
}

float WindowManager::GetWindowWidth()
{
	return width;
}

float WindowManager::GetWindowHeight()
{
	return height;
}