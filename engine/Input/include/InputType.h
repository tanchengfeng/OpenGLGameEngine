#pragma once
#include<variant>
#include "Keys.h"
#include "MouseButtons.h"

using InputType = std::variant<Key, MouseButton>;  //可以理解为安全版本的联合体，后续作为函数的参数可以统一不同输入源的类型