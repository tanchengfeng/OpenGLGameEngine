#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera {
private:
    //��ͼ������Ҫ��
    glm::vec3 m_Eye = { 0.0f, 0.0f, 1.0f };  //�����λ��
    glm::vec3 m_Target = { 0.0f, 0.0f, 0.0f };  //�Խ�λ��
    glm::vec3 m_Up = { 0.0f, 1.0f, 0.0f };  //��ֱ����

    //ͶӰ������Ҫ��
    float m_FOV = glm::radians(45.0f);  //��׶��ֱ��Ұ��Χ�������ƣ�
    float m_AspectRatio = 1.0f;  //�ӿڵĿ�߱�
    float m_Near = 0.1f;  //��С�ɼ����
    float m_Far = 100.0f;  //���ɼ����

    glm::mat4 m_ViewMatrix;
    glm::mat4 m_ProjectionMatrix;

    void UpdateViewMatrix();
    void UpdateProjectionMatrix();

public:
    Camera();  //����ʵ��������ʱ���������Ա������ֵ
    void SetEye(const glm::vec3& eye);
    void SetTarget(const glm::vec3& target);
    void SetUp(const glm::vec3& up);
    void SetFOV(float fov);
    void SetAspectRatio(float ratio);
    void SetNear(float nearZ);
    void SetFar(float farZ);
    void Camera::UpdateMatrices();  //ͬʱ������������

    //˽�к������ʽӿ�
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
