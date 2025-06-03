#pragma once
#include "InputState.h"
#include <GLFW/glfw3.h>

class InputManager {
public:
    static void Initialize(GLFWwindow* window);
    static void Update();
    static const InputState& GetState();

private:
    static GLFWwindow* m_Window;
    static InputState m_CurrentState;
};