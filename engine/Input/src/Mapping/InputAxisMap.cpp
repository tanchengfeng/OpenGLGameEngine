#include "Mapping/InputAxisMap.h"
#include <unordered_map>
#include <stdexcept>

//说明：在头文件中，创建虚拟轴时，所传入的键位类型是联合体类型，那么获取虚拟轴的值时，

//获取状态
float SignalAxisMap::GetPressedState(const InputType& source, const InputStateInfo& state)
{
    //对输入来源的实体进行萃取类型并且获取它的“持续按下”这一状态
    return std::visit([&](auto&& key) -> float {
        using T = std::decay_t<decltype(key)>;  //去掉各种类型修饰符，保留最原始的类型
        if constexpr (std::is_same_v<T, Key>)
        {
            auto it = state.keyStateMap.find(key);
            return (it != state.keyStateMap.end() && it->second.down) ? 1.0f : 0.0f;  //键是否存在于容器，是否处于持续按下的状态
        }
        else if constexpr (std::is_same_v<T, MouseButton>) {
            auto it = state.mouseStateMap.find(key);
            return (it != state.mouseStateMap.end() && it->second.down) ? 1.0f : 0.0f;
        }
        else
        {
            return 0.0f;
        }
        }, source);
}

//创建信号轴
void SignalAxisMap::CreateSignalAxis(const std::string axisName, AxisSignalPair axisSignalPair)
{
    m_SignalAxisMap.emplace(axisName, axisSignalPair);
}

//获取信号轴的值
float SignalAxisMap::GetSignalAxisValue(const std::string& axisName, const InputStateInfo& state)const
{
    auto it = m_SignalAxisMap.find(axisName);
    if (it == m_SignalAxisMap.end())
    {
        return 0.0f;  // 未找到该轴
    }

    const AxisSignalPair& pair = it->second;
    float posValue = GetPressedState(pair.positiveSignal, state);
    float negValue = -GetPressedState(pair.negativeSignal, state);  //消极的信号，那么要取相反数

    return posValue + negValue;   //信号叠加
}
