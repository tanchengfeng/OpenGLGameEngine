#pragma once
#include "WindowGL/Window.h"
#include "InputStateInfo.h"
#include "Keys.h"
#include "MouseButtons.h"

//本文件用于构建一个输入状态信息管理器

//两个注意点：1.输入窗口应该要使用封装好的窗口，即WindowGL，因为我们的引擎是有单独的窗口模块的。2.不需要手动设置输入状态，因为GLFW提供异步获取函数，即自动监听

class InputStateManager
{
private:
    WindowGL* m_Window;  //目标窗口代理

    //使用三缓冲机制，因为当前状态不一定就是新状态，需要综合老状态进行分析
    InputStateInfo m_OldStateInfo;  
    InputStateInfo m_NewStateInfo;
    InputStateInfo m_CurrentStateInfo;

public:
    InputStateManager(WindowGL* window);
    void SetWindow(WindowGL* window);  //设置目标代理
    void ClearState();  //清空状态（软重置）
    void UpdateState();  // 在每帧调用，负责刷新 old/new 并计算 current

    //获取私有成员接口
    const InputStateInfo& GetCurrentStateInfo();  //避免进行额外的拷贝，同时使用const限定外部修改权限

};