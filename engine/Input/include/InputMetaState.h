#pragma once
#include "KeySolids.h"
#include "MouseSolids.h"
#include <unordered_map>

//���ļ����ڶ��������ͼ��̼�λ��״̬�ṹ���Լ�����״̬����ν������״̬����һ������������Ԫ����������ʵ���ʵ���״̬�������� ��ID���״̬ ��ӳ��������

struct KeyState 
{
    bool down = false; //��������
    bool justPressed = false;  //˲ʱ����
    bool justReleased = false;  //˲ʱ�ɿ�
};

struct MouseState
{
    bool down = false;
    bool justPressed = false;
    bool justReleased = false;
};

struct InputState 
{
    std::unordered_map<KeySolid, KeyState> keyStates;  //���̼�λ״̬
    std::unordered_map<MouseButton, MouseState> mouseStates;  //����λ״̬
    float mouseDeltaX = 0.0f;
    float mouseDeltaY = 0.0f;
};
