#pragma once
#include<variant>
#include "Keys.h"
#include "MouseButtons.h"

using InputType = std::variant<Key, MouseButton>;  //�������Ϊ��ȫ�汾�������壬������Ϊ�����Ĳ�������ͳһ��ͬ����Դ������