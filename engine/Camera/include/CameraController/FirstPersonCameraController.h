#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "CameraController/CameraController.h"
#include "InputMetaState.h"

class FirstPersonCameraController :public CameraController
{
private:
    float m_yaw = -glm::half_pi<float>(); // 朝向 -Z ，因为我们的正方向是X，所以为了达到默认的视角，需要绕着Y轴旋转-π/2
    float m_pitch = 0.0f;  //默认不抬头
    float m_sensitivity = 0.01f;  //灵敏度
    float m_speed = 3.0f;  //摄像机每一帧移动的速度，帧偏移量=帧速度*帧持续时间

public:
    void SyncWithCamera();  //自动捕获所需的参数
    virtual void Update(float frameElapsed) override;  //重写更新函数

    //修改参数接口
    void OnMouseMove(float deltaX, float deltaY, float frameElapsed);  //鼠标控制
    void OnKeyboardInput(const InputState& keys, float frameElapsed);  //键位控制
    void SetYaw(float yaw);
    void SetPitch(float pitch);
    void SetSensitivity(float sensitivity);
    void SetSpeed(float speed);

    //私有属性访问接口
    float GetYaw();
    float GetPitch();
    float GetSensitivity();
    float GetSpeed();

};