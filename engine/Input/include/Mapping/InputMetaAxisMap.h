#pragma once
#include<string>
#include "InputMetaState.h"
#include "InputMetaBinding.h"

// 轴映射：处理“W+S、A+D”或手柄轴构成的 float 输入；用于处理持续的行为，例如人物移动、转动、蓄力等。
class AsixMap
{

public:
	void BindAxis(const std::string& name, InputSource positive, InputSource negative);
	float GetAxis(const std::string& name, const InputState& state) const;
};