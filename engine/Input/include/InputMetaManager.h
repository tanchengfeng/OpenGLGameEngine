#pragma once
#include "InputMetaState.h"
#include <GLFW/glfw3.h>

//本文件用于构建一个输入元管理器，输入元=实体+状态，更新状态、获取状态

class InputMetaManager
{
private:
    static GLFWwindow* m_Window;  //输入的目标代理
    static InputState m_CurrentState;

public:
    static void Initialize(GLFWwindow* window);  //初始化目标代理
    static void Update();
    static const InputState& GetState();

};