#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Camera/Camera.h"
#include "Character/Character.h"
#include "InputStateInfo.h"

class RoleController 
{
private:
    Character* m_Character;  // �������ݲ����
    float m_MoveSpeed = 3.0f;  //�����ƶ��ٶ�

public:
    void BindCharacter(Character* character);

    void Update(const InputStateInfo& inputState, float FrameElapsedTime);   //���������źŸ�������λ��

private:
    void UpdateMovement(const InputStateInfo& inputState, float FrameElapsedTime);
    void UpdateActions(const InputStateInfo& inputState);  
};
