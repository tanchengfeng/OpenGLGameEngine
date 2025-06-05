#include "InputStateManager.h"
#include "Keys.h"
#include "MouseButtons.h"
#include <cassert>

// 构造函数注入窗口
InputStateManager::InputStateManager(WindowGL* window): m_Window(window)
{
    assert(window != nullptr && "输入状态管理器得到一个无效的窗口指针！\n");
    ClearState();
}

// 目标输入窗口切换
void InputStateManager::SetWindow(WindowGL* window)
{
    assert(window != nullptr && "一个空的窗口指针，切换失败！\n");
    m_Window = window;
}

// 状态软重置（默认全部 false）
void InputStateManager::ClearState()
{
    m_OldStateInfo = InputStateInfo();  //使用默认状态对象进行赋值即可
    m_NewStateInfo = InputStateInfo();
    m_CurrentStateInfo = InputStateInfo();
}

// 每帧调用：更新所有状态缓冲
void InputStateManager::UpdateState()
{
    if (!m_Window) return;

    // 将当前状态作为旧状态保存（在获取新的键位状态之前，我们把上一帧的状态保存至旧状态缓冲）
    m_OldStateInfo = m_NewStateInfo;

    GLFWwindow* glfwWindow = m_Window->get_Window();  //获取到内部GLFW的窗口指针

    // 确定新的键位状态
    for (int i = GLFW_KEY_SPACE; i <= GLFW_KEY_LAST; ++i)   //遍历所有的键位，其中32~96为基本键的键码，256~348是功能键键码，并且键码不一定连续分布
    {
        int state = glfwGetKey(glfwWindow, i);  //glfw库提供的获取函数【硬件到程序】
        Key key = static_cast<Key>(i);
        m_NewStateInfo.keyStateMap.at(key).down = (state == GLFW_PRESS || state == GLFW_REPEAT);  //glfw库提供两种基本的状态，瞬间按下和瞬间松开
    }

    for (int i = GLFW_MOUSE_BUTTON_1; i <= GLFW_MOUSE_BUTTON_LAST; ++i) 
    {
        int state = glfwGetMouseButton(glfwWindow, i);
        MouseButton button = static_cast<MouseButton>(i);
        m_NewStateInfo.mouseStateMap.at(button).down = (state == GLFW_PRESS);
    }

    // 鼠标位置（增量）
    double xpos, ypos;
    glfwGetCursorPos(glfwWindow, &xpos, &ypos);  //鼠标在屏幕上移动，每一帧都构成一个向量
    m_NewStateInfo.mouseDeltaX = float(xpos) - m_CurrentStateInfo.mouseDeltaX;
    m_NewStateInfo.mouseDeltaY = float(ypos) - m_CurrentStateInfo.mouseDeltaY;

    // 确定键位最终状态
    // 1.键盘
    for (const auto& [key, newState] : m_NewStateInfo.keyStateMap)   //循环语法糖，pair元素可以直接展开
    {
        const bool oldDown = m_OldStateInfo.keyStateMap[key].down;
        bool newDown = newState.down;

        m_CurrentStateInfo.keyStateMap[key].down = newDown;
        m_CurrentStateInfo.keyStateMap[key].justPressed = newDown && !oldDown; //必须满足第一次按下才为真（旧松开新按下）
        m_CurrentStateInfo.keyStateMap[key].justReleased = !newDown && oldDown;  //旧按下新松开
    }
    // 鼠标
    for (const auto& [btn, newState] : m_NewStateInfo.mouseStateMap) 
    {
        const bool oldDown = m_OldStateInfo.mouseStateMap[btn].down;
        bool newDown = newState.down;

        m_CurrentStateInfo.mouseStateMap[btn].down = newDown;
        m_CurrentStateInfo.mouseStateMap[btn].justPressed = newDown && !oldDown;
        m_CurrentStateInfo.mouseStateMap[btn].justReleased = !newDown && oldDown;
    }

    // 更新鼠标移动信息
    m_CurrentStateInfo.mouseDeltaX = m_NewStateInfo.mouseDeltaX;
    m_CurrentStateInfo.mouseDeltaY = m_NewStateInfo.mouseDeltaY;
}

// 获取当前状态（只读）
const InputStateInfo& InputStateManager::GetCurrentStateInfo()
{
    return m_CurrentStateInfo;
}
