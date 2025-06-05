#include "Controller/CameraController.h"

void CameraController::SetCamera(Camera* Cam)
{
	m_Camera = Cam;
}

// 通过更新视线来更新投影矩阵
void CameraController::UpdateEyeLine()
{
	return;
}

Camera* CameraController::GetCamera()
{
	return m_Camera;
}