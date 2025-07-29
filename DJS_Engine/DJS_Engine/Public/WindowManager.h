#pragma once
#include <string>

struct GLFWwindow;
struct GLFWmonitor;
class DJS_ENGINE;

class WindowManager
{
	friend DJS_ENGINE;
private:
	std::string title = "DJS Engine";
	float windowWidth = 1600.0;
	float windowHeight = 900.0;
	float screenWidth = 1600.0;
	float screenHeight = 900.0;
	int screenRefreshRate = 0;
	GLFWwindow* window = nullptr;
	GLFWmonitor* monitor = nullptr;
	bool isFullscreen = false;
	bool isCursurHidden = false;

	bool Init();
	void Exit();

	void SwapBuffers();
	void PollEvents();
	void ClearBackground();

	void ChangeWindowSize();

public:
	void SetWindowSize(float width, float height);
	void SetWindowFullScreen(bool enableFullscreen);
	void SetWindowTitle(std::string title);
	void SetWindowIcon(std::string path);
	void SetCursorHidden(bool enableCursorHidden);
	float GetWindowWidth() const;
	float GetWindowHeight() const;
	float GetScreenWidth() const;
	float GetScreenHeight() const;
	bool GetIsFullscreen() const;
	GLFWwindow* GetWindow() const;
};
