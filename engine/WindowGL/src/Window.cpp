#include "WindowGL/Window.h"

//构造函数
WindowGL::WindowGL()
{
    pair<int, int> MonitorCoord = GetMonitorSize();
    m_Width = (int)(MonitorCoord.first * 0.8f);
    m_Height = (int)(MonitorCoord.second * 0.8f);
    m_ViewportWidth = m_Width;
    m_ViewportHeight = m_Height;
    m_Window = nullptr;
    m_bSwapBuffers = true;  //双缓冲机制
    m_bPollEvents = true;  //立即执行剩余事件
    m_ClearColor = glm::vec4(0.2f, 0.3f, 0.3f, 1.0f); //清空窗口所用颜色
}

//定义回调函数
void WindowGL::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);

    //我们需要获取更新后的视口大小，因为视口大小与摄像机的投影矩阵中视口宽高比有关，但是又因为视口尺寸是属性成员，非成员函数不能访问，所以需要将窗口与实例关联再访问。
    //将窗口（GLFWwindow*）与对应的 OpenGLWindow 类实例关联起来，以便在回调函数中访问类的成员变量和方法。
    WindowGL* glWindow = static_cast<WindowGL*>(glfwGetWindowUserPointer(window));
    glWindow->m_ViewportWidth = width;
    glWindow->m_ViewportHeight = height;

}

//获取显示器尺寸
std::pair<int, int> WindowGL::GetMonitorSize()
{
    // 获取主显示器
    GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
    if (!primaryMonitor)
    {
        throw std::runtime_error("无法获取主显示器");
    }

    // 获取显示器的视频模式
    const GLFWvidmode* videoMode = glfwGetVideoMode(primaryMonitor);
    if (!videoMode)
    {
        throw std::runtime_error("无法获取显示器的视频模式");
    }

    // 返回宽度和高度
    return { videoMode->width, videoMode->height };
}

//定义初始化函数
void WindowGL::InitWindow()
{
    //初始化GLFW库
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);  //主版本3.x
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);   //副版本x=3
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  //使用核心模式

    //准备渲染窗口  [建议基于显示器的百分比]
    m_Window = glfwCreateWindow(m_Width, m_Height, "My Window", nullptr, nullptr);

    //设置为活动窗口
    glfwMakeContextCurrent(m_Window);

    //视口大小回调
    glfwSetFramebufferSizeCallback(m_Window, framebuffer_size_callback);  //回调函数的设计通常不会绑定到成员函数，因为它是一个解决方案，不应该依赖于具体的某个对象

    //动态加载核心函数
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

}

//检查窗口是否处于活动状态
bool WindowGL::bActive()
{
    return !glfwWindowShouldClose(m_Window);
}

//是否启用双缓冲机制
void WindowGL::bUseSwapBuffers()
{
    if (m_bSwapBuffers)
    {
        glfwSwapBuffers(m_Window);
    }
}

//是否启用立即处理事件模式
void WindowGL::bUsePollEvents()
{
    if (m_bPollEvents)
    {
        glfwPollEvents();
    }
}

//清空屏幕
void WindowGL::Clear()
{
    glClearColor(m_ClearColor.x, m_ClearColor.y, m_ClearColor.z, m_ClearColor.w);
    glClear(GL_COLOR_BUFFER_BIT);
}

//获取私有属性接口
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
