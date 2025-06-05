#include "Controller/CharacterController.h"
#include <glm/gtx/norm.hpp>  // 用于 length2 优化平方距离计算

//绑定人物
void RoleController::BindCharacter(Character* character)
{
    m_Character = character;
}

//更新人物位置
void RoleController::Update(const InputStateInfo& inputState, float frameElapsedTime)
{
    if (!m_Character) return;

    UpdateMovement(inputState, frameElapsedTime);
    UpdateActions(inputState);  // 你未来可以加：跳跃、交互等
}

//基于移动的位置更新
void RoleController::UpdateMovement(const InputStateInfo& inputState, float frameElapsedTime)
{
    glm::vec3 movement(0.0f);

    // 获取摄像机的视线向量
    glm::vec3 forward = glm::normalize(m_Character->GetCamera()->GetTarget() - m_Character->GetCamera()->GetEye());
    forward.y = 0.0f;  // 角色移动一般不考虑抬头低头影响（在OpenGL中绑定的全局轴是Y轴）
    forward = glm::normalize(forward);

    glm::vec3 right = glm::normalize(glm::cross(forward, m_Character->GetCamera()->GetUp()));

    // WASD 映射移动方向
    if (inputState.keyStateMap.at(Key::W).down)
        movement += forward;
    if (inputState.keyStateMap.at(Key::S).down)
        movement -= forward;
    if (inputState.keyStateMap.at(Key::D).down)
        movement += right;
    if (inputState.keyStateMap.at(Key::A).down)
        movement -= right;

    // 移动归一化后乘速度
    if (glm::length2(movement) > 0.0001f)
    {
        movement = glm::normalize(movement) * m_MoveSpeed * frameElapsedTime;
        m_Character->Move(movement);  // 人物位置向指定的方向移动
    }
}

void RoleController::UpdateActions(const InputStateInfo& inputState)
{
    // 示例：跳跃（若将来有）
    /*
    if (inputState.keyStateMap.contains(Key::Space) &&
        inputState.keyStateMap.at(Key::Space) == KeyState::JustPressed)
    {
        m_Character->Jump();  // 角色数据层可选实现
    }
    */
}
