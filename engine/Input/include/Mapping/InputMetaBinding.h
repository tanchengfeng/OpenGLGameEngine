#pragma once
#include<variant>
#include "KeySolids.h"
#include "MouseSolids.h"

// �� std::variant ��֧�ְ���������λ��ͳһ����
using InputSource = std::variant<KeySolid, MouseButton>;