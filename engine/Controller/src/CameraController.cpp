#include "Controller/CameraController.h"

void CameraController::SetCamera(Camera* Cam)
{
	m_Camera = Cam;
}

// ͨ����������������ͶӰ����
void CameraController::UpdateEyeLine()
{
	return;
}

Camera* CameraController::GetCamera()
{
	return m_Camera;
}