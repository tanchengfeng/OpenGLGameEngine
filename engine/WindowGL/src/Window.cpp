#include "WindowGL/Window.h"

//���캯��
WindowGL::WindowGL()
{
    pair<int, int> MonitorCoord = GetMonitorSize();
    m_Width = (int)(MonitorCoord.first * 0.8f);
    m_Height = (int)(MonitorCoord.second * 0.8f);
    m_ViewportWidth = m_Width;
    m_ViewportHeight = m_Height;
    m_Window = nullptr;
    m_bSwapBuffers = true;  //˫�������
    m_bPollEvents = true;  //����ִ��ʣ���¼�
    m_ClearColor = glm::vec4(0.2f, 0.3f, 0.3f, 1.0f); //��մ���������ɫ
}

//����ص�����
void WindowGL::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);

    //������Ҫ��ȡ���º���ӿڴ�С����Ϊ�ӿڴ�С���������ͶӰ�������ӿڿ�߱��йأ���������Ϊ�ӿڳߴ������Գ�Ա���ǳ�Ա�������ܷ��ʣ�������Ҫ��������ʵ�������ٷ��ʡ�
    //�����ڣ�GLFWwindow*�����Ӧ�� OpenGLWindow ��ʵ�������������Ա��ڻص������з�����ĳ�Ա�����ͷ�����
    WindowGL* glWindow = static_cast<WindowGL*>(glfwGetWindowUserPointer(window));
    glWindow->m_ViewportWidth = width;
    glWindow->m_ViewportHeight = height;

}

//��ȡ��ʾ���ߴ�
std::pair<int, int> WindowGL::GetMonitorSize()
{
    // ��ȡ����ʾ��
    GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
    if (!primaryMonitor)
    {
        throw std::runtime_error("�޷���ȡ����ʾ��");
    }

    // ��ȡ��ʾ������Ƶģʽ
    const GLFWvidmode* videoMode = glfwGetVideoMode(primaryMonitor);
    if (!videoMode)
    {
        throw std::runtime_error("�޷���ȡ��ʾ������Ƶģʽ");
    }

    // ���ؿ�Ⱥ͸߶�
    return { videoMode->width, videoMode->height };
}

//�����ʼ������
void WindowGL::InitWindow()
{
    //��ʼ��GLFW��
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);  //���汾3.x
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);   //���汾x=3
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  //ʹ�ú���ģʽ

    //׼����Ⱦ����  [���������ʾ���İٷֱ�]
    m_Window = glfwCreateWindow(m_Width, m_Height, "My Window", nullptr, nullptr);

    //����Ϊ�����
    glfwMakeContextCurrent(m_Window);

    //�ӿڴ�С�ص�
    glfwSetFramebufferSizeCallback(m_Window, framebuffer_size_callback);  //�ص����������ͨ������󶨵���Ա��������Ϊ����һ�������������Ӧ�������ھ����ĳ������

    //��̬���غ��ĺ���
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

}

//��鴰���Ƿ��ڻ״̬
bool WindowGL::bActive()
{
    return !glfwWindowShouldClose(m_Window);
}

//�Ƿ�����˫�������
void WindowGL::bUseSwapBuffers()
{
    if (m_bSwapBuffers)
    {
        glfwSwapBuffers(m_Window);
    }
}

//�Ƿ��������������¼�ģʽ
void WindowGL::bUsePollEvents()
{
    if (m_bPollEvents)
    {
        glfwPollEvents();
    }
}

//�����Ļ
void WindowGL::Clear()
{
    glClearColor(m_ClearColor.x, m_ClearColor.y, m_ClearColor.z, m_ClearColor.w);
    glClear(GL_COLOR_BUFFER_BIT);
}

//��ȡ˽�����Խӿ�
GLFWwindow* WindowGL::get_Window()
{
    return m_Window;
}
int WindowGL::get_Width()
{
    return m_Width;
}
int WindowGL::get_Height()
{
    return m_Height;
}
int WindowGL::get_ViewportWidth()
{
    return m_ViewportWidth;
}
int WindowGL::get_ViewportHeight()
{
    return m_ViewportHeight;
}
