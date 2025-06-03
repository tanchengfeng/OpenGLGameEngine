#include "Graphics/Mesh.h"

//���캯��
Mesh::Mesh(vector<float> ModelVertex, const char* ModelFile)
{
    this->m_ModelVertex = ModelVertex;
    if (ModelFile != nullptr)
    {
        //��ȡģ�Ͷ������ݵ��߼�
    }

    //��GPU�˴�����Ӧ�Ķ���
    glGenVertexArrays(1, &m_VAO);
    glGenBuffers(1, &m_VBO);
    glGenBuffers(1, &m_EBO);

    //ģ�;������
    SetModelMatrix();

    //���ý���������ʵ�ֶ���ģ�Ͷ��󼴿�ʹ��
    ModelAnalysis();
}

//����ģ�;�����
void Mesh::SetModelMatrix(glm::vec3 scaleVec, float rotate, glm::vec3 rotateVec, glm::vec3 translateVec)
{
    //�����ر�˵�����������ֻдһ��Ԫ�أ�˵���Խ��߾�Ϊ��Ԫ�أ�������Ԫ�ؾ�Ϊ0�����һ������ֻдһ��Ԫ�أ�˵�����з����������Ԫ��

    //��������
    glm::mat4 m_ScaleMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(scaleVec));   //��һ���������������ṹ���ڶ�������ָ���Ǹ���������������������
    /*
    |1  0  0  0|         |scale_x      0           0          0|
    |0  1  0  0|  ��    |    0       scale_y      0          0|
    |0  0  1  0|  ��    |    0           0      scale_z      0|
    |0  0  0  1|         |    0           0           0          1|
    */

    // ��ת����
    glm::mat4 m_RotateMatrix = glm::rotate(glm::mat4(1.0f), rotate, glm::vec3(rotateVec));

    // ƽ�ƾ���
    glm::mat4 m_TranslateMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(translateVec));

    // ģ�;��� ���� �� ��ת �� ƽ��
    m_ModelMatrix = m_TranslateMatrix * m_RotateMatrix * m_ScaleMatrix;

}

Mesh::~Mesh()
{
    glDeleteVertexArrays(1, &m_VAO);
    glDeleteBuffers(1, &m_VBO);
    glDeleteBuffers(1, &m_EBO);
}

//ģ�ͽ�������
void Mesh::ModelAnalysis()
{
    //��VAO��ʼ��¼
    glBindVertexArray(m_VAO);

    //��VBO�ϴ�����
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, m_ModelVertex.size() * sizeof(float), m_ModelVertex.data(), GL_STATIC_DRAW);

    //�������Խ���������������Ϊ0��
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    //�������Խ���������������Ϊ1��
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    //�ر�VBO��VAO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}


//˽�к����ӿ�
PrimitiveInfo Mesh::get_PrimitiveInfo()
{
    return m_PrimitiveInfo;
}
GLuint Mesh::get_VAO()
{
    return m_VAO;
}
glm::mat4 Mesh::get_ModelMatrix()
{
    return m_ModelMatrix;
}

