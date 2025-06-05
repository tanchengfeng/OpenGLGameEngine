#include "Controller/CharacterController.h"
#include <glm/gtx/norm.hpp>  // ���� length2 �Ż�ƽ���������

//������
void RoleController::BindCharacter(Character* character)
{
    m_Character = character;
}

//��������λ��
void RoleController::Update(const InputStateInfo& inputState, float frameElapsedTime)
{
    if (!m_Character) return;

    UpdateMovement(inputState, frameElapsedTime);
    UpdateActions(inputState);  // ��δ�����Լӣ���Ծ��������
}

//�����ƶ���λ�ø���
void RoleController::UpdateMovement(const InputStateInfo& inputState, float frameElapsedTime)
{
    glm::vec3 movement(0.0f);

    // ��ȡ���������������
    glm::vec3 forward = glm::normalize(m_Character->GetCamera()->GetTarget() - m_Character->GetCamera()->GetEye());
    forward.y = 0.0f;  // ��ɫ�ƶ�һ�㲻����̧ͷ��ͷӰ�죨��OpenGL�а󶨵�ȫ������Y�ᣩ
    forward = glm::normalize(forward);

    glm::vec3 right = glm::normalize(glm::cross(forward, m_Character->GetCamera()->GetUp()));

    // WASD ӳ���ƶ�����
    if (inputState.keyStateMap.at(Key::W).down)
        movement += forward;
    if (inputState.keyStateMap.at(Key::S).down)
        movement -= forward;
    if (inputState.keyStateMap.at(Key::D).down)
        movement += right;
    if (inputState.keyStateMap.at(Key::A).down)
        movement -= right;

    // �ƶ���һ������ٶ�
    if (glm::length2(movement) > 0.0001f)
    {
        movement = glm::normalize(movement) * m_MoveSpeed * frameElapsedTime;
        m_Character->Move(movement);  // ����λ����ָ���ķ����ƶ�
    }
}

void RoleController::UpdateActions(const InputStateInfo& inputState)
{
    // ʾ������Ծ���������У�
    /*
    if (inputState.keyStateMap.contains(Key::Space) &&
        inputState.keyStateMap.at(Key::Space) == KeyState::JustPressed)
    {
        m_Character->Jump();  // ��ɫ���ݲ��ѡʵ��
    }
    */
}
