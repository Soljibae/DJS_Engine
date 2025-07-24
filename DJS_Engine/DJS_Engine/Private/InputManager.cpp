#include "InputManager.h"
#include "DJS_ENGINE.h"
#include  "GLFW/glfw3.h"

void InputManager::Init(GLFWwindow* window)
{
	this->window = window;

	currKeyStates.resize(GLFW_KEY_LAST + 1, KeyState::NONE);
	prevKeyStates.resize(GLFW_KEY_LAST + 1, false);

	currMouseStates.resize(GLFW_MOUSE_BUTTON_LAST + 1, KeyState::NONE);
	prevMouseStates.resize(GLFW_MOUSE_BUTTON_LAST + 1, false);
}

void InputManager::Update()
{
    for (int key = 0; key <= GLFW_KEY_LAST; ++key)
    {
        bool isCurrDown = (glfwGetKey(window, key) == GLFW_PRESS);
        bool isPrevDown = prevKeyStates[key];

        if (!isPrevDown && isCurrDown)
            currKeyStates[key] = KeyState::PRESSED;
        else if (isPrevDown && isCurrDown)
            currKeyStates[key] = KeyState::DOWN;
        else if (isPrevDown && !isCurrDown)
            currKeyStates[key] = KeyState::RELEASED;
        else
            currKeyStates[key] = KeyState::NONE;

        prevKeyStates[key] = isCurrDown;
    }

    for (int button = 0; button <= GLFW_MOUSE_BUTTON_LAST; ++button)
    {
        bool isCurrDown = (glfwGetMouseButton(window, button) == GLFW_PRESS);
        bool isPrevDown = prevMouseStates[button];

        if (!isPrevDown && isCurrDown)
            currMouseStates[button] = KeyState::PRESSED;
        else if (isPrevDown && isCurrDown)
            currMouseStates[button] = KeyState::DOWN;
        else if (isPrevDown && !isCurrDown)
            currMouseStates[button] = KeyState::RELEASED;
        else
            currMouseStates[button] = KeyState::NONE;

        prevMouseStates[button] = isCurrDown;
    }

    double x, y;
    glfwGetCursorPos(window, &x, &y);
    mouseX = static_cast<float>(x);
    mouseY = static_cast<float>(y);
}

bool InputManager::IsKeyPressed(int key) const
{
    if (currKeyStates[key] == KeyState::PRESSED)
        return true;

    return false;
}

bool InputManager::IsKeyReleased(int key) const
{
    if (currKeyStates[key] == KeyState::RELEASED)
        return true;

    return false;
}

bool InputManager::IsKeyDown(int key) const
{
    if (currKeyStates[key] == KeyState::DOWN)
        return true;

    return false;
}

bool InputManager::IsMousePressed(int button) const
{
    if(currMouseStates[button] == KeyState::PRESSED)
        return true;

    return false;
}

bool InputManager::IsMouseReleased(int button) const
{
    if (currMouseStates[button] == KeyState::RELEASED)
        return true;

    return false;
}

bool InputManager::IsMouseDown(int button) const
{
    if (currMouseStates[button] == KeyState::DOWN)
        return true;

    return false;
}

float InputManager::GetMousePosX() const
{
	return mouseX;
}

float InputManager::GetMousePosY() const
{
	return mouseY;
}