#include "CameraController/FirstPersonCameraController.h"


void FirstPersonCameraController::SyncWithCamera() 
{
	glm::vec3 front = glm::normalize(GetCamera()->GetTarget() - GetCamera()->GetEye());
	m_pitch = asin(front.y);
	m_yaw = atan2(front.x, front.z);
}

void FirstPersonCameraController::Update(float frameElapsed)
{
	glm::vec3 direction;
	direction.x = glm::cos(m_pitch) * glm::sin(m_yaw)*m_speed* frameElapsed;
	direction.y = glm::sin(m_pitch) * m_speed * frameElapsed;
	direction.z = glm::cos(m_pitch) * glm::cos(m_yaw) * m_speed * frameElapsed;
	direction = glm::normalize(direction);  //标准化

	glm::vec3 CameraEye = GetCamera()->GetEye();  //获取所持有的摄像机的位置
	GetCamera()->SetTarget(CameraEye + direction);  //目标位置=摄像机位置+视线方向

}

//修改参数接口
void FirstPersonCameraController::OnMouseMove(float deltaX, float deltaY, float frameElapsed)
{
	//预留
}
void FirstPersonCameraController::OnKeyboardInput(const InputState& keys, float frameElapsed)
{
	//预留
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

//私有属性访问接口
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