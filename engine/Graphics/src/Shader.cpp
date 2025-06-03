#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Graphics/Shader.h"


//���캯��
ShaderProgram::ShaderProgram(const char* VertexFilePath, const char* FragmentFilePath)
{
    this->m_VertexFilePath = VertexFilePath;
    this->m_FragmentFilePath = FragmentFilePath;
    m_VertexShader = glCreateShader(GL_VERTEX_SHADER);  //��Ա�����������Զ��޸�
    m_FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    m_MainShaderProgram = glCreateProgram();

    //�ȱ�������ɫ���ٳ�ʼ������ɫ�����Ӷ�ʵ�ֶ�����󼴿�ʹ��
    CompileShader();
    InitShaderProgram();
}

//��������
ShaderProgram::~ShaderProgram()
{
    glDeleteShader(m_VertexShader);
    glDeleteShader(m_FragmentShader);
    glDeleteProgram(m_MainShaderProgram);
}

//1.���������ɫ��Դ�뺯��
void ShaderProgram::CompileShader()   //��һ��������ʾ��ǰԴ���Ӧ����ɫ��
{
    ifstream VertexInputStrem(m_VertexFilePath);  //�ļ�������
    ifstream FragmentInputStrem(m_FragmentFilePath);
    stringstream VertexStringStrem;  //�ַ�����
    stringstream FragmentStringStrem;

    //����ת��
    VertexStringStrem << VertexInputStrem.rdbuf();
    FragmentStringStrem << FragmentInputStrem.rdbuf();

    // ��ȡ�ַ���
    std::string VertexString = VertexStringStrem.str();
    std::string FragmentString = FragmentStringStrem.str();

    // ��ȡ�ַ�����Ӧ���ַ������ַ
    const char* VertexSource = VertexString.c_str();
    const char* FragmentSource = FragmentString.c_str();

    //��Դ����ص���ɫ������
    glShaderSource(m_VertexShader, 1, &VertexSource, nullptr);  //�������Ҫ����Դ���ַ�������Ķ���ָ��
    glShaderSource(m_FragmentShader, 1, &FragmentSource, nullptr);

    //���붥����ɫ��
    glCompileShader(m_VertexShader);
    int success;
    glGetShaderiv(m_VertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        char infoLog[512];
        glGetShaderInfoLog(m_VertexShader, 512, nullptr, infoLog);
        cerr << "Shader Compile Error: " << infoLog << endl;
    }

    //����Ƭ����ɫ��
    glCompileShader(m_FragmentShader);
    glGetShaderiv(m_FragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        char infoLog[512];
        glGetShaderInfoLog(m_FragmentShader, 512, nullptr, infoLog);
        cerr << "Shader Compile Error: " << infoLog << endl;
    }
}

//2.��������ɫ������
void ShaderProgram::InitShaderProgram()
{
    //������ɫ����������ɫ��
    glAttachShader(m_MainShaderProgram, m_VertexShader);
    glAttachShader(m_MainShaderProgram, m_FragmentShader);

    //����
    glLinkProgram(m_MainShaderProgram);

    int success;
    glGetProgramiv(m_MainShaderProgram, GL_LINK_STATUS, &success);
    if (!success)
    {
        char infoLog[512];
        glGetProgramInfoLog(m_MainShaderProgram, 512, nullptr, infoLog);
        cerr << "Program Link Error: " << infoLog << endl;
    }

    //ɾ������ɫ��
    glDeleteShader(m_VertexShader);
    glDeleteShader(m_FragmentShader);

}

//3.
void ShaderProgram::UseShaderProgram()
{
    glUseProgram(m_MainShaderProgram);  //�޸�֮ǰҪ��ʹ�ö�Ӧ�ĳ���
}


//��ȡ˽�����Խӿ�
GLuint ShaderProgram::get_ShaderProgram()
{
    return m_MainShaderProgram;
}


