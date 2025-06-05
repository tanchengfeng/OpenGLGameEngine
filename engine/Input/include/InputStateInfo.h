#pragma once
#include <unordered_map>
#include "Keys.h"
#include "MouseButtons.h"

//本文件用于定义鼠标键和键盘键位的状态结构，以及输入状态信息（构建 键ID与键状态 的映射容器）

struct KeyState 
{
    bool down = false; //持续按下
    bool justPressed = false;  //瞬时按下
    bool justReleased = false;  //瞬时松开
};

struct MouseState
{
    bool down = false;
    bool justPressed = false;
    bool justReleased = false;
};

struct InputStateInfo
{
    std::unordered_map<Key, KeyState> keyStateMap;  //键盘键位状态
    std::unordered_map<MouseButton, MouseState> mouseStateMap;  //鼠标键位状态
    float mouseDeltaX = 0.0f;
    float mouseDeltaY = 0.0f;
};
