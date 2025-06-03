#pragma once
#include<variant>
#include "KeySolids.h"
#include "MouseSolids.h"

// 用 std::variant 来支持按键和鼠标键位的统一处理
using InputSource = std::variant<KeySolid, MouseButton>;