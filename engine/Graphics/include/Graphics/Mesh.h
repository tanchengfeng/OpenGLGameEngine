#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include<iostream>
#include<vector>
#include<map>
#include<functional>

using namespace std;

struct PrimitiveInfo
{
	GLenum Rule = GL_TRIANGLES;  //装配规则
	int FirstVertexIndex = 0;  //第一个图元从哪个顶点索引开始
	int SingleVertexCounts = 3;  //单个图元的顶点个数
};

class Mesh
{
private:
	vector<float> m_ModelVertex;  //模型顶点数据
	PrimitiveInfo m_PrimitiveInfo; //模型的单个图元信息
	int m_FirstVertexIndex = 0;

	const float PI = 3.1415926f;
	glm::mat4 m_ModelMatrix;  //模型矩阵
	GLuint m_VAO = 0, m_VBO = 0, m_EBO = 0;  //三个GPU对象ID
public:
	Mesh(vector<float> ModelVec, const char* ModelFile = nullptr);
	~Mesh();

	//设置矩阵模型函数，其中，默认的配置：放缩因子倍数均为1，旋转角度为0，绕着z轴旋转，不发生平移
	void SetModelMatrix(glm::vec3 scaleVec = { 1.0f, 1.0f, 1.0f }, float rotate = 0.0f, glm::vec3 rotateVec = { 0.0f, 0.0f, 1.0f }, glm::vec3 translateVec = { 0.0f, 0.0f, 0.0f });

	//模型的顶点解析函数
	void ModelAnalysis();

public:
	PrimitiveInfo get_PrimitiveInfo();
	GLuint get_VAO();
	glm::mat4 get_ModelMatrix();
};