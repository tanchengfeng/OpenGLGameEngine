#pragma once
#include<string>
#include "InputState.h"
#include "InputBinding.h"

// 行为映射：用于判断 "是否按下 Jump"、"是否释放 Fire" 等
class ActionMap
{

public:
	void BindAction(const std::string& name, InputSource source);
	bool IsJustPressed(const std::string& name, const InputState& state) const;
};

