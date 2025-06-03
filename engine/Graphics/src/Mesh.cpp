#include "Graphics/Mesh.h"

//构造函数
Mesh::Mesh(vector<float> ModelVertex, const char* ModelFile)
{
    this->m_ModelVertex = ModelVertex;
    if (ModelFile != nullptr)
    {
        //读取模型顶点数据的逻辑
    }

    //在GPU端创建相应的对象
    glGenVertexArrays(1, &m_VAO);
    glGenBuffers(1, &m_VBO);
    glGenBuffers(1, &m_EBO);

    //模型矩阵计算
    SetModelMatrix();

    //调用解析函数，实现定义模型对象即可使用
    ModelAnalysis();
}

//计算模型矩阵函数
void Mesh::SetModelMatrix(glm::vec3 scaleVec, float rotate, glm::vec3 rotateVec, glm::vec3 translateVec)
{
    //矩阵特别说明：如果矩阵只写一个元素，说明对角线均为该元素，其余与元素均为0；如果一个向量只写一个元素，说明所有分量均是这个元素

    //放缩矩阵
    glm::mat4 m_ScaleMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(scaleVec));   //第一个参数表明基础结构，第二个参数指的是各个分量放缩倍数的向量
    /*
    |1  0  0  0|         |scale_x      0           0          0|
    |0  1  0  0|  →    |    0       scale_y      0          0|
    |0  0  1  0|  →    |    0           0      scale_z      0|
    |0  0  0  1|         |    0           0           0          1|
    */

    // 旋转矩阵
    glm::mat4 m_RotateMatrix = glm::rotate(glm::mat4(1.0f), rotate, glm::vec3(rotateVec));

    // 平移矩阵
    glm::mat4 m_TranslateMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(translateVec));

    // 模型矩阵： 缩放 → 旋转 → 平移
    m_ModelMatrix = m_TranslateMatrix * m_RotateMatrix * m_ScaleMatrix;

}

Mesh::~Mesh()
{
    glDeleteVertexArrays(1, &m_VAO);
    glDeleteBuffers(1, &m_VBO);
    glDeleteBuffers(1, &m_EBO);
}

//模型解析函数
void Mesh::ModelAnalysis()
{
    //打开VAO开始记录
    glBindVertexArray(m_VAO);

    //打开VBO上传数据
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, m_ModelVertex.size() * sizeof(float), m_ModelVertex.data(), GL_STATIC_DRAW);

    //顶点属性解析规则（属性索引为0）
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    //顶点属性解析规则（属性索引为1）
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    //关闭VBO和VAO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}


//私有函数接口
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

