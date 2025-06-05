#pragma once
#include<string>
#include "InputStateInfo.h"
#include "InputType.h"

//��ӳ�䣺Ϊ�˹��������������λ�ź�״̬����������ź�(1)��������ź�(-1)�����ź�(0)���ڱ�����������һ����������������븺����������ͬʱ���������ĵ���ЧӦ������ͬʱ����
//		  'W'��'S'��ô���ý����0�����ﲻ�ƶ���
//�����ǵ�һ����������Ϊ�ɶ�����������ʱ�������Զ�ά������ʾ����ô���Թ��������ӳ�䣬ÿ�������һ�������������Ṳͬ�����������Ϊ�ϡ�
//�����������ڶ�֡����Ч���ϣ�ͨ�������ǵ��������е�����������ģ��ȷ���ģ����Ի�ȡ��ķ���ֵ��������״̬֮һ��

//һ�黥Ϊ�෴�ļ�λ�źŶ�
struct AxisSignalPair
{
	InputType positiveSignal;
	InputType negativeSignal;
};

class SignalAxisMap
{
private:
	std::unordered_map<std::string, AxisSignalPair> m_SignalAxisMap;  //������

public:
	void CreateSignalAxis(const std::string axisName, AxisSignalPair axisSignalPair);  //�����ź���
	
	float GetSignalAxisValue(const std::string& axisName, const InputStateInfo& state) const;    //��ȡ�ź����ֵ��������֪�ļ�λ״̬�����жϣ�

	static float GetPressedState(const InputType& source, const InputStateInfo& state);  //��ȡ����ʵ��ĳ�����ס״̬
};