#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Graphics/Shader.h"


//构造函数
ShaderProgram::ShaderProgram(const char* VertexFilePath, const char* FragmentFilePath)
{
    this->m_VertexFilePath = VertexFilePath;
    this->m_FragmentFilePath = FragmentFilePath;
    m_VertexShader = glCreateShader(GL_VERTEX_SHADER);  //成员函数操作均自动修改
    m_FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    m_MainShaderProgram = glCreateProgram();

    //先编译子着色器再初始化主着色器，从而实现定义对象即可使用
    CompileShader();
    InitShaderProgram();
}

//析构函数
ShaderProgram::~ShaderProgram()
{
    glDeleteShader(m_VertexShader);
    glDeleteShader(m_FragmentShader);
    glDeleteProgram(m_MainShaderProgram);
}

//1.编译各个着色器源码函数
void ShaderProgram::CompileShader()   //第一个参数表示当前源码对应的着色器
{
    ifstream VertexInputStrem(m_VertexFilePath);  //文件输入流
    ifstream FragmentInputStrem(m_FragmentFilePath);
    stringstream VertexStringStrem;  //字符串流
    stringstream FragmentStringStrem;

    //流的转换
    VertexStringStrem << VertexInputStrem.rdbuf();
    FragmentStringStrem << FragmentInputStrem.rdbuf();

    // 获取字符串
    std::string VertexString = VertexStringStrem.str();
    std::string FragmentString = FragmentStringStrem.str();

    // 获取字符串对应的字符数组地址
    const char* VertexSource = VertexString.c_str();
    const char* FragmentSource = FragmentString.c_str();

    //将源码加载到着色器对象
    glShaderSource(m_VertexShader, 1, &VertexSource, nullptr);  //这个函数要的是源码字符串数组的二级指针
    glShaderSource(m_FragmentShader, 1, &FragmentSource, nullptr);

    //编译顶点着色器
    glCompileShader(m_VertexShader);
    int success;
    glGetShaderiv(m_VertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        char infoLog[512];
        glGetShaderInfoLog(m_VertexShader, 512, nullptr, infoLog);
        cerr << "Shader Compile Error: " << infoLog << endl;
    }

    //编译片段着色器
    glCompileShader(m_FragmentShader);
    glGetShaderiv(m_FragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        char infoLog[512];
        glGetShaderInfoLog(m_FragmentShader, 512, nullptr, infoLog);
        cerr << "Shader Compile Error: " << infoLog << endl;
    }
}

//2.创建主着色器程序
void ShaderProgram::InitShaderProgram()
{
    //将子着色器附在主着色器
    glAttachShader(m_MainShaderProgram, m_VertexShader);
    glAttachShader(m_MainShaderProgram, m_FragmentShader);

    //链接
    glLinkProgram(m_MainShaderProgram);

    int success;
    glGetProgramiv(m_MainShaderProgram, GL_LINK_STATUS, &success);
    if (!success)
    {
        char infoLog[512];
        glGetProgramInfoLog(m_MainShaderProgram, 512, nullptr, infoLog);
        cerr << "Program Link Error: " << infoLog << endl;
    }

    //删除子着色器
    glDeleteShader(m_VertexShader);
    glDeleteShader(m_FragmentShader);

}

//3.
void ShaderProgram::UseShaderProgram()
{
    glUseProgram(m_MainShaderProgram);  //修改之前要先使用对应的程序
}


//获取私有属性接口
GLuint ShaderProgram::get_ShaderProgram()
{
    return m_MainShaderProgram;
}


