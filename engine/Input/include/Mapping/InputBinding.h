#pragma once
#include<variant>
#include "KeyCodes.h"
#include "MouseCodes.h"

// �� std::variant ��֧�ְ���������λ��ͳһ����
using InputSource = std::variant<KeyCode, MouseButton>;