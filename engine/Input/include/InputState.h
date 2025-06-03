#pragma once
#include "KeyCodes.h"
#include "MouseCodes.h"
#include <unordered_map>

//本文件用于定义鼠标键和键盘键位的状态结构，以及输入状态，所谓的输入状态就是一个完整的输入元，包括输入实体和实体的状态，即构建 键ID与键状态 的映射容器。

struct KeyState 
{
    bool down = false;
    bool justPressed = false;
    bool justReleased = false;
};

struct MouseState
{
    bool down = false;
    bool justPressed = false;
    bool justReleased = false;
};

struct InputState 
{
    std::unordered_map<KeyCode, KeyState> keyStates;
    std::unordered_map<MouseButton, MouseState> mouseStates;
    float mouseDeltaX = 0.0f;
    float mouseDeltaY = 0.0f;
};
