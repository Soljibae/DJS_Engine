#pragma once

struct GLFWwindow;

class InputManager {
private:
	GLFWwindow* window = nullptr;
public:
	void Init(GLFWwindow* window);
	void Exit();
};