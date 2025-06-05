#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Camera/Camera.h"
#include "Character/Character.h"
#include "InputStateInfo.h"

class RoleController 
{
private:
    Character* m_Character;  // 人物数据层对象
    float m_MoveSpeed = 3.0f;  //人物移动速度

public:
    void BindCharacter(Character* character);

    void Update(const InputStateInfo& inputState, float FrameElapsedTime);   //基于输入信号更新人物位置

private:
    void UpdateMovement(const InputStateInfo& inputState, float FrameElapsedTime);
    void UpdateActions(const InputStateInfo& inputState);  
};
