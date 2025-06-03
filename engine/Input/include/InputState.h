#pragma once
#include "KeyCodes.h"
#include "MouseCodes.h"
#include <unordered_map>

//���ļ����ڶ��������ͼ��̼�λ��״̬�ṹ���Լ�����״̬����ν������״̬����һ������������Ԫ����������ʵ���ʵ���״̬�������� ��ID���״̬ ��ӳ��������

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
