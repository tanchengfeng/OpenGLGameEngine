#pragma once
#include "Camera/Camera.h"

//��Ҫְ�𣺻��������ˮƽ��ת�Ƕ� Yaw ����ֱ��ת�Ƕ� Pitch ����������������߷����Լ�Ӹ�����ͼ���󣨲���ԽȨֱ�Ӹ��£��������Camera�����ṩ�ĸ��½ӿڣ�

class CameraController
{
private:
	Camera* m_Camera; //ά��һ�������ʵ���Ĵ���

public:
	void SetCamera(Camera* Cam);  //������ʱ�л�����
	virtual void Update(float FrameElapsed) = 0;  //ͨ���漰����ת�����ƶ��ĸ����߼���Ҫ����һ֡�ĳ���ʱ�䣬���ⲻͬˢ���ʵ��豸�ڵ�λʱ��Ϊ��ɵ�λ�Ʋ�һ��

	//���ʽӿ�
	Camera* GetCamera();
};
