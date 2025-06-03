#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "CameraController/CameraController.h"
#include "InputMetaState.h"

class FirstPersonCameraController :public CameraController
{
private:
    float m_yaw = -glm::half_pi<float>(); // ���� -Z ����Ϊ���ǵ���������X������Ϊ�˴ﵽĬ�ϵ��ӽǣ���Ҫ����Y����ת-��/2
    float m_pitch = 0.0f;  //Ĭ�ϲ�̧ͷ
    float m_sensitivity = 0.01f;  //������
    float m_speed = 3.0f;  //�����ÿһ֡�ƶ����ٶȣ�֡ƫ����=֡�ٶ�*֡����ʱ��

public:
    void SyncWithCamera();  //�Զ���������Ĳ���
    virtual void Update(float frameElapsed) override;  //��д���º���

    //�޸Ĳ����ӿ�
    void OnMouseMove(float deltaX, float deltaY, float frameElapsed);  //������
    void OnKeyboardInput(const InputState& keys, float frameElapsed);  //��λ����
    void SetYaw(float yaw);
    void SetPitch(float pitch);
    void SetSensitivity(float sensitivity);
    void SetSpeed(float speed);

    //˽�����Է��ʽӿ�
    float GetYaw();
    float GetPitch();
    float GetSensitivity();
    float GetSpeed();

};