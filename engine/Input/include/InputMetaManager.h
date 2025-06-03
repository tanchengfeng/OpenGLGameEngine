#pragma once
#include "InputMetaState.h"
#include <GLFW/glfw3.h>

//���ļ����ڹ���һ������Ԫ������������Ԫ=ʵ��+״̬������״̬����ȡ״̬

class InputMetaManager
{
private:
    static GLFWwindow* m_Window;  //�����Ŀ�����
    static InputState m_CurrentState;

public:
    static void Initialize(GLFWwindow* window);  //��ʼ��Ŀ�����
    static void Update();
    static const InputState& GetState();

};