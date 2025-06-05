#include "Mapping/InputAxisMap.h"
#include <unordered_map>
#include <stdexcept>

//˵������ͷ�ļ��У�����������ʱ��������ļ�λ���������������ͣ���ô��ȡ�������ֵʱ��

//��ȡ״̬
float SignalAxisMap::GetPressedState(const InputType& source, const InputStateInfo& state)
{
    //��������Դ��ʵ�������ȡ���Ͳ��һ�ȡ���ġ��������¡���һ״̬
    return std::visit([&](auto&& key) -> float {
        using T = std::decay_t<decltype(key)>;  //ȥ�������������η���������ԭʼ������
        if constexpr (std::is_same_v<T, Key>)
        {
            auto it = state.keyStateMap.find(key);
            return (it != state.keyStateMap.end() && it->second.down) ? 1.0f : 0.0f;  //���Ƿ�������������Ƿ��ڳ������µ�״̬
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

//�����ź���
void SignalAxisMap::CreateSignalAxis(const std::string axisName, AxisSignalPair axisSignalPair)
{
    m_SignalAxisMap.emplace(axisName, axisSignalPair);
}

//��ȡ�ź����ֵ
float SignalAxisMap::GetSignalAxisValue(const std::string& axisName, const InputStateInfo& state)const
{
    auto it = m_SignalAxisMap.find(axisName);
    if (it == m_SignalAxisMap.end())
    {
        return 0.0f;  // δ�ҵ�����
    }

    const AxisSignalPair& pair = it->second;
    float posValue = GetPressedState(pair.positiveSignal, state);
    float negValue = -GetPressedState(pair.negativeSignal, state);  //�������źţ���ôҪȡ�෴��

    return posValue + negValue;   //�źŵ���
}
