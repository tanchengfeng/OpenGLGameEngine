#include "InputStateManager.h"
#include "Keys.h"
#include "MouseButtons.h"
#include <cassert>

// ���캯��ע�봰��
InputStateManager::InputStateManager(WindowGL* window): m_Window(window)
{
    assert(window != nullptr && "����״̬�������õ�һ����Ч�Ĵ���ָ�룡\n");
    ClearState();
}

// Ŀ�����봰���л�
void InputStateManager::SetWindow(WindowGL* window)
{
    assert(window != nullptr && "һ���յĴ���ָ�룬�л�ʧ�ܣ�\n");
    m_Window = window;
}

// ״̬�����ã�Ĭ��ȫ�� false��
void InputStateManager::ClearState()
{
    m_OldStateInfo = InputStateInfo();  //ʹ��Ĭ��״̬������и�ֵ����
    m_NewStateInfo = InputStateInfo();
    m_CurrentStateInfo = InputStateInfo();
}

// ÿ֡���ã���������״̬����
void InputStateManager::UpdateState()
{
    if (!m_Window) return;

    // ����ǰ״̬��Ϊ��״̬���棨�ڻ�ȡ�µļ�λ״̬֮ǰ�����ǰ���һ֡��״̬��������״̬���壩
    m_OldStateInfo = m_NewStateInfo;

    GLFWwindow* glfwWindow = m_Window->get_Window();  //��ȡ���ڲ�GLFW�Ĵ���ָ��

    // ȷ���µļ�λ״̬
    for (int i = GLFW_KEY_SPACE; i <= GLFW_KEY_LAST; ++i)   //�������еļ�λ������32~96Ϊ�������ļ��룬256~348�ǹ��ܼ����룬���Ҽ��벻һ�������ֲ�
    {
        int state = glfwGetKey(glfwWindow, i);  //glfw���ṩ�Ļ�ȡ������Ӳ��������
        Key key = static_cast<Key>(i);
        m_NewStateInfo.keyStateMap.at(key).down = (state == GLFW_PRESS || state == GLFW_REPEAT);  //glfw���ṩ���ֻ�����״̬��˲�䰴�º�˲���ɿ�
    }

    for (int i = GLFW_MOUSE_BUTTON_1; i <= GLFW_MOUSE_BUTTON_LAST; ++i) 
    {
        int state = glfwGetMouseButton(glfwWindow, i);
        MouseButton button = static_cast<MouseButton>(i);
        m_NewStateInfo.mouseStateMap.at(button).down = (state == GLFW_PRESS);
    }

    // ���λ�ã�������
    double xpos, ypos;
    glfwGetCursorPos(glfwWindow, &xpos, &ypos);  //�������Ļ���ƶ���ÿһ֡������һ������
    m_NewStateInfo.mouseDeltaX = float(xpos) - m_CurrentStateInfo.mouseDeltaX;
    m_NewStateInfo.mouseDeltaY = float(ypos) - m_CurrentStateInfo.mouseDeltaY;

    // ȷ����λ����״̬
    // 1.����
    for (const auto& [key, newState] : m_NewStateInfo.keyStateMap)   //ѭ���﷨�ǣ�pairԪ�ؿ���ֱ��չ��
    {
        const bool oldDown = m_OldStateInfo.keyStateMap[key].down;
        bool newDown = newState.down;

        m_CurrentStateInfo.keyStateMap[key].down = newDown;
        m_CurrentStateInfo.keyStateMap[key].justPressed = newDown && !oldDown; //���������һ�ΰ��²�Ϊ�棨���ɿ��°��£�
        m_CurrentStateInfo.keyStateMap[key].justReleased = !newDown && oldDown;  //�ɰ������ɿ�
    }
    // ���
    for (const auto& [btn, newState] : m_NewStateInfo.mouseStateMap) 
    {
        const bool oldDown = m_OldStateInfo.mouseStateMap[btn].down;
        bool newDown = newState.down;

        m_CurrentStateInfo.mouseStateMap[btn].down = newDown;
        m_CurrentStateInfo.mouseStateMap[btn].justPressed = newDown && !oldDown;
        m_CurrentStateInfo.mouseStateMap[btn].justReleased = !newDown && oldDown;
    }

    // ��������ƶ���Ϣ
    m_CurrentStateInfo.mouseDeltaX = m_NewStateInfo.mouseDeltaX;
    m_CurrentStateInfo.mouseDeltaY = m_NewStateInfo.mouseDeltaY;
}

// ��ȡ��ǰ״̬��ֻ����
const InputStateInfo& InputStateManager::GetCurrentStateInfo()
{
    return m_CurrentStateInfo;
}
