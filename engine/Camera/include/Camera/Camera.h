#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera {
private:
    //视图矩阵三要素
    glm::vec3 m_Eye = { 0.0f, 0.0f, 1.0f };  //摄像机位置
    glm::vec3 m_Target = { 0.0f, 0.0f, 0.0f };  //对焦位置
    glm::vec3 m_Up = { 0.0f, 1.0f, 0.0f };  //竖直向量

    //投影矩阵三要素
    float m_FOV = glm::radians(45.0f);  //视锥竖直视野范围（弧度制）
    float m_AspectRatio = 1.0f;  //视口的宽高比
    float m_Near = 0.1f;  //最小可见深度
    float m_Far = 100.0f;  //最大可见深度

    glm::mat4 m_ViewMatrix;
    glm::mat4 m_ProjectionMatrix;

    void UpdateViewMatrix();
    void UpdateProjectionMatrix();

public:
    Camera();  //避免实例化对象时两个矩阵成员是垃圾值
    void SetEye(const glm::vec3& eye);
    void SetTarget(const glm::vec3& target);
    void SetUp(const glm::vec3& up);
    void SetFOV(float fov);
    void SetAspectRatio(float ratio);
    void SetNear(float nearZ);
    void SetFar(float farZ);
    void Camera::UpdateMatrices();  //同时更新两个矩阵

    //私有函数访问接口
    glm::vec3 GetEye() const;
    glm::vec3 GetTarget() const;
    glm::vec3 GetUp() const;
    float GetFOV() const;
    float GetAspectRatio() const;
    float GetNear() const;
    float GetFar() const;
    glm::mat4 GetViewMatrix() const;
    glm::mat4 GetProjectionMatrix() const;
};
