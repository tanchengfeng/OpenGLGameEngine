#include "InputMetaManager.h"

//���ļ����ڹ���һ������Ԫ������������Ԫ=ʵ��+״̬������ ��ʼ��״̬������״̬����ȡ״̬

static void InputMetaManager::Initialize(GLFWwindow* window);
static void InputMetaManager::Update();
static const InputState& GetState();

static GLFWwindow* m_Window;
static InputState m_CurrentState;

