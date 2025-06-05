#pragma once
#include "Camera/Camera.h"

//主要职责：基于输入的水平旋转角度 Yaw 和竖直旋转角度 Pitch 来计算摄像机的视线方向，以间接更新视图矩阵（不能越权直接更新，必须调用Camera对象提供的更新接口）

class CameraController
{
private:
	Camera* m_Camera; //维护一个摄像机实例的代理

public:
	void SetCamera(Camera* Cam);  //可以随时切换代理

	//通过更新视线来更新投影矩阵
	virtual void UpdateEyeLine() = 0;  //视线永远是单位向量，不直接和帧持续时间相关

	//访问接口
	Camera* GetCamera();
};

