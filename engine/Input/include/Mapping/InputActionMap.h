#pragma once
#include <unordered_map>
#include <vector>
#include <string>
#include "InputType.h"       
#include "InputStateInfo.h"     // 输入状态快照
#include "InputAxisMap.h"

// 动作映射系统：用于绑定离散行为（如跳跃、攻击等）
class ActionMap
{
private:
    std::unordered_map<std::string, std::vector<InputType>> m_SignalActionMap;  //维护动作名称和动作键值

public:
    // 绑定动作名到一组输入源（一个动作可以绑定多个键或鼠标按钮）
    void BindAction(const std::string& name, const InputType& source);

    // 查询某动作在此帧是否触发
    bool IsActionTriggered(const std::string& name, const InputStateInfo& state) const;

    // 给持续性的动作进行键位绑定
    bool IsActionPressed(const std::string& name, const InputStateInfo& state) const;
};


