#pragma once
#include <string>

class GLFWwindow;

class WindowManager
{
public:
	bool Init();
	void Exit();

	void SwapBuffers();

	void SetWindowSize(float width, float height);
	void SetWindowTitle(std::string title);
	void SetWindowIcon();
	float GetWindowWidth();
	float GetWindowHeight();
private:
	std::string title = "DJS Engine";
	float width = 1600.0;
	float height = 900.0;
	GLFWwindow* window;
};
