#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Camera/Camera.h"

class Character
{
    glm::vec3 m_position;  // λ��
    glm::vec3 m_velocity;   //

    Camera* m_camera = nullptr;  // ���۾������

public:
    void SetCamera(Camera* camera);
    void UpdateCameraPos();  // λ��һ��͸��������

    void Move(glm::vec3 delta);  //��ָ���ķ����ƶ���ƽ���ı��η���

    //����˽�����Խӿ�
    glm::vec3 GetPosition() const;
    Camera* GetCamera() const;
};

