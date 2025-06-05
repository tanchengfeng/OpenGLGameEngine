#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Camera/Camera.h"

class Character
{
    glm::vec3 m_position;  // 位置
    glm::vec3 m_velocity;   //

    Camera* m_camera = nullptr;  // “眼睛”组件

public:
    void SetCamera(Camera* camera);
    void UpdateCameraPos();  // 位置一变就更新摄像机

    void Move(glm::vec3 delta);  //向指定的方向移动（平行四边形法则）

    //访问私有属性接口
    glm::vec3 GetPosition() const;
    Camera* GetCamera() const;
};

