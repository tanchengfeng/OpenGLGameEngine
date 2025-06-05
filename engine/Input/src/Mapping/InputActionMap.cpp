#include "Mapping/InputActionMap.h"
#include <algorithm>

void ActionMap::BindAction(const std::string& name, const InputType& source)
{
    m_SignalActionMap[name].push_back(source);
}

//���ĳ�������Ƿ񴥷�
bool ActionMap::IsActionTriggered(const std::string& name, const InputStateInfo& state) const
{
    auto it = m_SignalActionMap.find(name);
    if (it == m_SignalActionMap.end()) return false;

    for (const auto& source : it->second)
    {
        bool triggered = std::visit([&](auto&& key) -> bool {
            using T = std::decay_t<decltype(key)>;  //ȥ���������η�
            if constexpr (std::is_same_v<T, Key>)
            {
                auto it = state.keyStateMap.find(key);
                return (it!= state.keyStateMap .end() && it->second.justPressed);  //˲�䰴��ʱ����
            }
                
            else if constexpr (std::is_same_v<T, MouseButton>)
            {
                auto it = state.mouseStateMap.find(key);
                return (it != state.mouseStateMap.end() && it->second.justPressed);
            }
            else
                return false;
            }, source);

        if (triggered) return true;
    }

    return false;
}


//�������ԵĶ������а󶨼�λ
bool ActionMap::IsActionPressed(const std::string& name, const InputStateInfo& state) const
{
    // �ж��źŶ��������Ƿ����Ŀ�궯��
    auto it = m_SignalActionMap.find(name);
    if (it == m_SignalActionMap.end()) return false;

    for (const auto& source : it->second) 
    {
        if (SignalAxisMap::GetPressedState(source, state) > 0.5f)   //Ԥ��δ����ǿ����ֵ���������ڿ��Լ�������д
        {
            return true;
        }
    }
    return false;
}


