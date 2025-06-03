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
	GLenum Rule = GL_TRIANGLES;  //װ�����
	int FirstVertexIndex = 0;  //��һ��ͼԪ���ĸ�����������ʼ
	int SingleVertexCounts = 3;  //����ͼԪ�Ķ������
};

class Mesh
{
private:
	vector<float> m_ModelVertex;  //ģ�Ͷ�������
	PrimitiveInfo m_PrimitiveInfo; //ģ�͵ĵ���ͼԪ��Ϣ
	int m_FirstVertexIndex = 0;

	const float PI = 3.1415926f;
	glm::mat4 m_ModelMatrix;  //ģ�;���
	GLuint m_VAO = 0, m_VBO = 0, m_EBO = 0;  //����GPU����ID
public:
	Mesh(vector<float> ModelVec, const char* ModelFile = nullptr);
	~Mesh();

	//���þ���ģ�ͺ��������У�Ĭ�ϵ����ã��������ӱ�����Ϊ1����ת�Ƕ�Ϊ0������z����ת��������ƽ��
	void SetModelMatrix(glm::vec3 scaleVec = { 1.0f, 1.0f, 1.0f }, float rotate = 0.0f, glm::vec3 rotateVec = { 0.0f, 0.0f, 1.0f }, glm::vec3 translateVec = { 0.0f, 0.0f, 0.0f });

	//ģ�͵Ķ����������
	void ModelAnalysis();

public:
	PrimitiveInfo get_PrimitiveInfo();
	GLuint get_VAO();
	glm::mat4 get_ModelMatrix();
};