#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <utility>
#include<iostream>
#include<map>
using namespace std;

class WindowGL
{
private:
	GLFWwindow* m_Window;
	int m_Width;
	int m_Height;
	int m_ViewportWidth;
	int m_ViewportHeight;
	bool m_bSwapBuffers;  //˫�������
	bool m_bPollEvents;  //����ִ��ʣ���¼�
	glm::vec4 m_ClearColor; //��մ���������ɫ

public:
	WindowGL();
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);  //�ص�������������ǳ�Ա����
	pair<int, int> GetMonitorSize();
	void InitWindow();
	bool bActive();
	void bUseSwapBuffers();
	void bUsePollEvents();
	void Clear();

public:
	GLFWwindow* get_Window();
	int get_Width();
	int get_Height();
	int get_ViewportWidth();
	int get_ViewportHeight();
};
