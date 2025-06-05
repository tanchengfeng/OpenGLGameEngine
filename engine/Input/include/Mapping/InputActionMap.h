#pragma once
#include <unordered_map>
#include <vector>
#include <string>
#include "InputType.h"       
#include "InputStateInfo.h"     // ����״̬����
#include "InputAxisMap.h"

// ����ӳ��ϵͳ�����ڰ���ɢ��Ϊ������Ծ�������ȣ�
class ActionMap
{
private:
    std::unordered_map<std::string, std::vector<InputType>> m_SignalActionMap;  //ά���������ƺͶ�����ֵ

public:
    // �󶨶�������һ������Դ��һ���������԰󶨶��������갴ť��
    void BindAction(const std::string& name, const InputType& source);

    // ��ѯĳ�����ڴ�֡�Ƿ񴥷�
    bool IsActionTriggered(const std::string& name, const InputStateInfo& state) const;

    // �������ԵĶ������м�λ��
    bool IsActionPressed(const std::string& name, const InputStateInfo& state) const;
};


