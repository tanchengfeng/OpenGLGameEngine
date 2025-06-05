#pragma once
#include<string>
#include "InputStateInfo.h"
#include "InputType.h"

//轴映射：为了构建三个的输入键位信号状态，即正相关信号(1)、负相关信号(-1)、无信号(0)。在表现上类似于一个坐标轴的正半轴与负半轴向量，同时满足向量的叠加效应，例如同时按下
//		  'W'和'S'那么作用结果是0，人物不移动。
//当我们的一个连续性行为由多种特征决定时，即可以多维向量表示，那么可以构建多个轴映射，每个轴代表一个分量，最后多轴共同作用在这个行为上。
//连续性体现在多帧叠加效果上，通常，我们的轴所持有的正负向量的模是确定的，所以获取轴的返回值就是三个状态之一。

//一组互为相反的键位信号对
struct AxisSignalPair
{
	InputType positiveSignal;
	InputType negativeSignal;
};

class SignalAxisMap
{
private:
	std::unordered_map<std::string, AxisSignalPair> m_SignalAxisMap;  //轴容器

public:
	void CreateSignalAxis(const std::string axisName, AxisSignalPair axisSignalPair);  //创建信号轴
	
	float GetSignalAxisValue(const std::string& axisName, const InputStateInfo& state) const;    //获取信号轴的值（根据已知的键位状态进行判断）

	static float GetPressedState(const InputType& source, const InputStateInfo& state);  //获取输入实体的持续按住状态
};