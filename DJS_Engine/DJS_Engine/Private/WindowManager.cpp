#define STB_IMAGE_IMPLEMENTATION
#include "STBImage/stb_image.h"
#include "WindowManager.h"
#include "DJS_ENGINE.h"
#include  "GLFW/glfw3.h"
#include <iostream>

bool WindowManager::Init()
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	window = glfwCreateWindow(static_cast<int>(windowWidth), static_cast<int>(windowHeight), title.c_str(), NULL, NULL);

	if (!window)
	{
		std::cerr << "Failed to create GLFW window" << std::endl;
		return false;
	}

	monitor = glfwGetPrimaryMonitor();
	if (monitor == nullptr) {
		std::cerr << "Failed to get primary monitor" << std::endl;
		glfwTerminate();
		return false;
	}

	const GLFWvidmode* mode = glfwGetVideoMode(monitor);
	if (mode == nullptr) {
		std::cerr << "Failed to get video mode for the primary monitor" << std::endl;
		glfwTerminate();
		return false;
	}

	screenWidth = static_cast<float>(mode->width);
	screenHeight = static_cast<float>(mode->height);
	screenRefreshRate = mode->refreshRate;

	glfwMakeContextCurrent(window);

	glClearColor(1.f, 1.f, 1.f, 1.0f);

	return true;
}

void WindowManager::Exit()
{
	glfwDestroyWindow(window);
}

void WindowManager::SwapBuffers()
{
	glfwSwapBuffers(window);
}

void WindowManager::PollEvents()
{
	glfwPollEvents();
}

void WindowManager::SetWindowSize(float width, float height)
{
	windowWidth = width;
	windowHeight = height;
	
	if(!isFullscreen)
		ChangeWindowSize();
}

void WindowManager::SetWindowFullScreen(bool enableFullscreen)
{
	isFullscreen = enableFullscreen;

	ChangeWindowSize();
}

void WindowManager::SetWindowTitle(std::string title)
{
	this->title = title;
	glfwSetWindowTitle(window, this->title.c_str());
}

void WindowManager::SetCursorHidden(bool enableCursorHidden)
{
	if (enableCursorHidden)
	{
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

	}
	else
	{
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	}
}

void WindowManager::ClearBackground()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void WindowManager::SetWindowIcon(std::string path)
{
	GLFWimage images[1];
	int width, height, channels;
	unsigned char* pixels = stbi_load(path.c_str(), &width, &height, &channels, 4);

	images[0].width = width;
	images[0].height = height;
	images[0].pixels = pixels;

	glfwSetWindowIcon(window, 1, images);

	stbi_image_free(pixels);
}

float WindowManager::GetWindowWidth() const
{
	return windowWidth;
}

float WindowManager::GetWindowHeight() const
{
	return windowHeight;
}

float WindowManager::GetScreenWidth() const
{
	return screenWidth;
}

float WindowManager::GetScreenHeight() const
{
	return screenHeight;
}

bool WindowManager::GetIsFullscreen() const
{
	return isFullscreen;
}

GLFWwindow* WindowManager::GetWindow() const
{
	return window;
}

void WindowManager::ChangeWindowSize()
{
	if (isFullscreen)
	{
		glfwSetWindowMonitor(window, monitor, 0, 0, static_cast<int>(screenWidth), static_cast<int>(screenHeight), screenRefreshRate);
	}
	else
	{
		int xPos = static_cast<int>((screenWidth - windowWidth) / 2.f);
		int yPos = static_cast<int>((screenHeight - windowHeight) / 2.f);

		glfwSetWindowMonitor(window, monitor, xPos, yPos, static_cast<int>(windowWidth), static_cast<int>(windowHeight), 0);
	}
}