#include "Character/Character.h"

void Character::SetCamera(Camera* camera)
{
    m_camera = camera;
    // ��ʼ��ʱͬ��һ��λ��
    if (m_camera)
        m_camera->SetEye(m_position);
}


void Character::UpdateCameraPos()
{
    if (m_camera)
    {
        m_camera->SetEye(m_position);  // ��ɫ��λ�� = �������λ��
        // Ҳ���Ը�����Ҫ����ƫ�ƣ������һ�˳ƻ�����˳Ƹ߶�ƫ��
        // m_camera->SetEye(m_position + glm::vec3(0.0f, 1.8f, 0.0f));
    }
}

// ��ָ���ķ����ƶ�
void Character::Move(glm::vec3 delta)
{
    m_position += delta;
    UpdateCameraPos();  // �ƶ����Զ����������λ��
}

//˽�����Է��ʽӿ�
glm::vec3 Character::GetPosition() const
{
    return m_position;
}

Camera* Character::GetCamera() const
{
    return m_camera;
}

