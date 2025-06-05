#pragma once
#include <unordered_map>
#include "Keys.h"
#include "MouseButtons.h"

//���ļ����ڶ��������ͼ��̼�λ��״̬�ṹ���Լ�����״̬��Ϣ������ ��ID���״̬ ��ӳ��������

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

struct InputStateInfo
{
    std::unordered_map<Key, KeyState> keyStateMap;  //���̼�λ״̬
    std::unordered_map<MouseButton, MouseState> mouseStateMap;  //����λ״̬
    float mouseDeltaX = 0.0f;
    float mouseDeltaY = 0.0f;
};
