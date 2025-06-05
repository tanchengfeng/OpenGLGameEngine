#pragma once
#include "Camera/Camera.h"

//��Ҫְ�𣺻��������ˮƽ��ת�Ƕ� Yaw ����ֱ��ת�Ƕ� Pitch ����������������߷����Լ�Ӹ�����ͼ���󣨲���ԽȨֱ�Ӹ��£��������Camera�����ṩ�ĸ��½ӿڣ�

class CameraController
{
private:
	Camera* m_Camera; //ά��һ�������ʵ���Ĵ���

public:
	void SetCamera(Camera* Cam);  //������ʱ�л�����

	//ͨ����������������ͶӰ����
	virtual void UpdateEyeLine() = 0;  //������Զ�ǵ�λ��������ֱ�Ӻ�֡����ʱ�����

	//���ʽӿ�
	Camera* GetCamera();
};

