#include "Mapping/InputActionMap.h"
#include <algorithm>

void ActionMap::BindAction(const std::string& name, const InputType& source)
{
    m_SignalActionMap[name].push_back(source);
}

//检测某个动作是否触发
bool ActionMap::IsActionTriggered(const std::string& name, const InputStateInfo& state) const
{
    auto it = m_SignalActionMap.find(name);
    if (it == m_SignalActionMap.end()) return false;

    for (const auto& source : it->second)
    {
        bool triggered = std::visit([&](auto&& key) -> bool {
            using T = std::decay_t<decltype(key)>;  //去掉类型修饰符
            if constexpr (std::is_same_v<T, Key>)
            {
                auto it = state.keyStateMap.find(key);
                return (it!= state.keyStateMap .end() && it->second.justPressed);  //瞬间按下时触发
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


//给持续性的动作进行绑定键位
bool ActionMap::IsActionPressed(const std::string& name, const InputStateInfo& state) const
{
    // 判断信号动作容器是否存在目标动作
    auto it = m_SignalActionMap.find(name);
    if (it == m_SignalActionMap.end()) return false;

    for (const auto& source : it->second) 
    {
        if (SignalAxisMap::GetPressedState(source, state) > 0.5f)   //预留未来的强度阈值，所以现在可以兼容性书写
        {
            return true;
        }
    }
    return false;
}


