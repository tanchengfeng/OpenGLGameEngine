#include "Controller/CameraController.h"

void CameraController::SetCamera(Camera* Cam)
{
	m_Camera = Cam;
}

void CameraController::Update(float FrameElapsed)
{
	return;
}

Camera* CameraController::GetCamera()
{
	return m_Camera;
}