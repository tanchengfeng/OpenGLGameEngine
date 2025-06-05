#include "Controller/FirstPersonCameraController.h"
#include "Keys.h"

//��ȡ�������ˮƽת���Ǻ���ֱת����
void FirstPersonCameraController::SyncWithCamera() 
{
	glm::vec3 front = glm::normalize(GetCamera()->GetTarget() - GetCamera()->GetEye());
	m_pitch = asin(front.y);
	m_yaw = atan2(front.x, front.z);
}

//ͨ����������������ͶӰ����
void FirstPersonCameraController::UpdateEyeLine()
{
	glm::vec3 direction;
	direction.x = glm::cos(m_pitch) * glm::sin(m_yaw);
	direction.y = glm::sin(m_pitch);
	direction.z = glm::cos(m_pitch) * glm::cos(m_yaw);
	direction = glm::normalize(direction);  //��׼��

	glm::vec3 CameraEye = GetCamera()->GetEye();  //��ȡ�����е��������λ��
	GetCamera()->SetTarget(CameraEye + direction);  //����ͶӰ�������У�Ŀ��λ��=�����λ��+���߷���

}

//���ⲿ��ȡ��Ϣȥ���������״̬
void FirstPersonCameraController::OnMouseMove(float deltaX, float deltaY, float frameElapsed)   //�����Ҫ����Yaw��Pitch
{
	//deltaX��ӦYaw��deltaY��ӦPitch
	m_yaw += deltaX * m_sensitivity;  //���������ȿ�����Ч������ת�ķ���
	m_pitch += deltaY * m_sensitivity;

	// Clamp pitch ��ֹ�������ת
	const float maxPitch = glm::radians(89.0f);  // �ӽ�90�ȵ�����90
	m_pitch = glm::clamp(m_pitch, -maxPitch, maxPitch);

	UpdateEyeLine();  // ���½Ƕȸ��������Ŀ���
}

//����ģʽ�µ�λ�ø���
void FirstPersonCameraController::OnKeyboardInput(const InputStateInfo& keys, float frameElapsed)
{
	glm::vec3 forward = glm::normalize(GetCamera()->GetTarget() - GetCamera()->GetEye());
	glm::vec3 right = glm::normalize(glm::cross(forward, GetCamera()->GetUp()));   //��Ϊ��ֱ����ͨ����˼���

	glm::vec3 movement(0.0f);
	if (keys.keyStateMap.at(Key::W).down) movement += forward;
	if (keys.keyStateMap.at(Key::S).down) movement -= forward;
	if (keys.keyStateMap.at(Key::D).down) movement += right;
	if (keys.keyStateMap.at(Key::A).down) movement -= right;

	if (glm::length(movement) > 0.0f)
	{
		movement = glm::normalize(movement);
		glm::vec3 eye = GetCamera()->GetEye();
		eye += movement * m_speed * frameElapsed;    //�����������λ��
		GetCamera()->SetEye(eye);  //���¼������λ��ͬʱ�Զ���ͼ����

		// Ŀ��ҲҪ����
		UpdateEyeLine();
	}
}

void FirstPersonCameraController::SetYaw(float yaw)
{
	m_yaw = yaw;
}
void FirstPersonCameraController::SetPitch(float pitch)
{
	m_pitch = pitch;
}
void FirstPersonCameraController::SetSensitivity(float sensitivity)
{
	m_sensitivity = sensitivity;
}
void FirstPersonCameraController::SetSpeed(float speed)
{
	m_speed = speed;
}

//˽�����Է��ʽӿ�
float FirstPersonCameraController::GetYaw()
{
	return m_yaw;
}
float FirstPersonCameraController::GetPitch()
{
	return m_pitch;
}
float FirstPersonCameraController::GetSensitivity()
{
	return m_sensitivity;
}
float FirstPersonCameraController::GetSpeed()
{
	return m_speed;
}