#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include<string>
using namespace std;

//˵�����޸�ȫ�ֱ���uniformӦ��������Ⱦģ��Ĺ������������ﲻ�ṩ

class ShaderProgram
{
private:
    const char* m_VertexFilePath;  //������ɫ���ļ�·��
    const char* m_FragmentFilePath;  //Ƭ����ɫ���ļ�·��
    GLuint m_VertexShader;
    GLuint m_FragmentShader;
    GLuint m_MainShaderProgram;
public:
    ShaderProgram(const char* VertexFilePath, const char* FragmentFilePath);
    ~ShaderProgram();
    void CompileShader();  //��������ɫ��
    void InitShaderProgram();  //��������ɫ������
    void UseShaderProgram();  //��ʽʹ������ɫ������

public:
    GLuint get_ShaderProgram();
};
