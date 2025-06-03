#pragma once
#include<string>
#include "InputState.h"
#include "InputBinding.h"

// ��Ϊӳ�䣺�����ж� "�Ƿ��� Jump"��"�Ƿ��ͷ� Fire" ��
class ActionMap
{

public:
	void BindAction(const std::string& name, InputSource source);
	bool IsJustPressed(const std::string& name, const InputState& state) const;
};

