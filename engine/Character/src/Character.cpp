#include "Character/Character.h"

void Character::SetCamera(Camera* camera)
{
    m_camera = camera;
    // 初始化时同步一次位置
    if (m_camera)
        m_camera->SetEye(m_position);
}


void Character::UpdateCameraPos()
{
    if (m_camera)
    {
        m_camera->SetEye(m_position);  // 角色的位置 = 摄像机的位置
        // 也可以根据需要附加偏移，例如第一人称或第三人称高度偏移
        // m_camera->SetEye(m_position + glm::vec3(0.0f, 1.8f, 0.0f));
    }
}

// 向指定的方向移动
void Character::Move(glm::vec3 delta)
{
    m_position += delta;
    UpdateCameraPos();  // 移动后自动更新摄像机位置
}

//私有属性访问接口
glm::vec3 Character::GetPosition() const
{
    return m_position;
}

Camera* Character::GetCamera() const
{
    return m_camera;
}

