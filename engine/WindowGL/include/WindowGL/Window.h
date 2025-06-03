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
	bool m_bSwapBuffers;  //双缓冲机制
	bool m_bPollEvents;  //立即执行剩余事件
	glm::vec4 m_ClearColor; //清空窗口所用颜色

public:
	WindowGL();
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);  //回调解决方案不能是成员函数
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
