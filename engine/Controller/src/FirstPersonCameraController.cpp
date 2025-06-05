#include "Controller/FirstPersonCameraController.h"
#include "Keys.h"

//获取摄像机的水平转动角和竖直转动角
void FirstPersonCameraController::SyncWithCamera() 
{
	glm::vec3 front = glm::normalize(GetCamera()->GetTarget() - GetCamera()->GetEye());
	m_pitch = asin(front.y);
	m_yaw = atan2(front.x, front.z);
}

//通过更新视线来更新投影矩阵
void FirstPersonCameraController::UpdateEyeLine()
{
	glm::vec3 direction;
	direction.x = glm::cos(m_pitch) * glm::sin(m_yaw);
	direction.y = glm::sin(m_pitch);
	direction.z = glm::cos(m_pitch) * glm::cos(m_yaw);
	direction = glm::normalize(direction);  //标准化

	glm::vec3 CameraEye = GetCamera()->GetEye();  //获取所持有的摄像机的位置
	GetCamera()->SetTarget(CameraEye + direction);  //更新投影矩阵。其中，目标位置=摄像机位置+视线方向

}

//从外部获取信息去更新摄像机状态
void FirstPersonCameraController::OnMouseMove(float deltaX, float deltaY, float frameElapsed)   //鼠标主要控制Yaw与Pitch
{
	//deltaX对应Yaw；deltaY对应Pitch
	m_yaw += deltaX * m_sensitivity;  //乘上灵敏度可以有效控制旋转的幅度
	m_pitch += deltaY * m_sensitivity;

	// Clamp pitch 防止摄像机翻转
	const float maxPitch = glm::radians(89.0f);  // 接近90度但不达90
	m_pitch = glm::clamp(m_pitch, -maxPitch, maxPitch);

	UpdateEyeLine();  // 用新角度更新摄像机目标点
}

//自由模式下的位置更新
void FirstPersonCameraController::OnKeyboardInput(const InputStateInfo& keys, float frameElapsed)
{
	glm::vec3 forward = glm::normalize(GetCamera()->GetTarget() - GetCamera()->GetEye());
	glm::vec3 right = glm::normalize(glm::cross(forward, GetCamera()->GetUp()));   //互为垂直可以通过叉乘计算

	glm::vec3 movement(0.0f);
	if (keys.keyStateMap.at(Key::W).down) movement += forward;
	if (keys.keyStateMap.at(Key::S).down) movement -= forward;
	if (keys.keyStateMap.at(Key::D).down) movement += right;
	if (keys.keyStateMap.at(Key::A).down) movement -= right;

	if (glm::length(movement) > 0.0f)
	{
		movement = glm::normalize(movement);
		glm::vec3 eye = GetCamera()->GetEye();
		eye += movement * m_speed * frameElapsed;    //计算摄像机的位置
		GetCamera()->SetEye(eye);  //更新计算机的位置同时自动视图矩阵

		// 目标也要更新
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