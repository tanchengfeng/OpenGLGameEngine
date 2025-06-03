#pragma once
#include "Camera/Camera.h"

//主要职责：基于输入的水平旋转角度 Yaw 和竖直旋转角度 Pitch 来计算摄像机的视线方向，以间接更新视图矩阵（不能越权直接更新，必须调用Camera对象提供的更新接口）

class CameraController
{
private:
	Camera* m_Camera; //维护一个摄像机实例的代理

public:
	void SetCamera(Camera* Cam);  //可以随时切换代理
	virtual void Update(float FrameElapsed) = 0;  //通常涉及到旋转或者移动的更新逻辑都要考虑一帧的持续时间，避免不同刷新率的设备在单位时间为造成的位移不一致

	//访问接口
	Camera* GetCamera();
};
