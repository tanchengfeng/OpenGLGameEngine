#include "Camera/Camera.h"

//构造函数
Camera::Camera() 
{
	UpdateViewMatrix();
	UpdateProjectionMatrix();
}

//1.修改视图矩阵
void Camera::SetEye(const glm::vec3& eye)
{
	m_Eye = eye;
	UpdateViewMatrix();
}
void Camera::SetTarget(const glm::vec3& target)
{
	m_Target = target;
	UpdateViewMatrix();
}
void Camera::SetUp(const glm::vec3& up)
{
	m_Up = up;
	UpdateViewMatrix();
}

//2.修改投影矩阵
void Camera::SetFOV(float NewFOV)
{
	m_FOV = NewFOV;
	UpdateProjectionMatrix();
}
void Camera::SetAspectRatio(float ratio)
{
	m_AspectRatio = ratio;
	UpdateProjectionMatrix();
}
void Camera::SetNear(float nearZ)
{
	m_Near = nearZ;
	UpdateProjectionMatrix();
}
void Camera::SetFar(float farZ)
{
	m_Far = farZ;
	UpdateProjectionMatrix();
}

//3.同时更新两个矩阵
void Camera::UpdateMatrices() 
{
	UpdateViewMatrix();
	UpdateProjectionMatrix();
}

//封装两个重复调用的函数
void Camera::UpdateViewMatrix()
{
	m_ViewMatrix = glm::lookAt(m_Eye, m_Target, m_Up);
}
void Camera::UpdateProjectionMatrix()
{
	m_ProjectionMatrix = glm::perspective(m_FOV, m_AspectRatio, m_Near, m_Far);
}


//私有属性访问接口
glm::vec3 Camera::GetEye() const
{
	return m_Eye;
}
glm::vec3 Camera::GetTarget() const
{
	return m_Target;
}
glm::vec3 Camera::GetUp() const
{
	return m_Up;
}
float Camera::GetFOV() const
{
	return m_FOV;
}
float Camera::GetAspectRatio() const
{
	return m_AspectRatio;
}
float Camera::GetNear() const
{
	return m_Near;
}
float Camera::GetFar() const
{
	return m_Far;
}
glm::mat4 Camera::GetViewMatrix() const
{
	return m_ViewMatrix;
}
glm::mat4 Camera::GetProjectionMatrix() const
{
	return m_ProjectionMatrix;
}

