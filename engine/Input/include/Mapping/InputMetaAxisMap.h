#pragma once
#include<string>
#include "InputMetaState.h"
#include "InputMetaBinding.h"

// ��ӳ�䣺����W+S��A+D�����ֱ��ṹ�ɵ� float ���룻���ڴ����������Ϊ�����������ƶ���ת���������ȡ�
class AsixMap
{

public:
	void BindAxis(const std::string& name, InputSource positive, InputSource negative);
	float GetAxis(const std::string& name, const InputState& state) const;
};