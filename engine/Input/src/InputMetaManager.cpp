#include "InputMetaManager.h"

//本文件用于构建一个输入元管理器，输入元=实体+状态，包括 初始化状态、更新状态、获取状态

static void InputMetaManager::Initialize(GLFWwindow* window);
static void InputMetaManager::Update();
static const InputState& GetState();

static GLFWwindow* m_Window;
static InputState m_CurrentState;

