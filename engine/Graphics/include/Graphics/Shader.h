#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include<string>
using namespace std;

//说明：修改全局变量uniform应该属于渲染模块的工作，所以这里不提供

class ShaderProgram
{
private:
    const char* m_VertexFilePath;  //顶点着色器文件路径
    const char* m_FragmentFilePath;  //片段着色器文件路径
    GLuint m_VertexShader;
    GLuint m_FragmentShader;
    GLuint m_MainShaderProgram;
public:
    ShaderProgram(const char* VertexFilePath, const char* FragmentFilePath);
    ~ShaderProgram();
    void CompileShader();  //编译子着色器
    void InitShaderProgram();  //创建主着色器程序
    void UseShaderProgram();  //显式使用主着色器程序

public:
    GLuint get_ShaderProgram();
};
