#pragma once
#include "WindowGL/Window.h"
#include "InputStateInfo.h"
#include "Keys.h"
#include "MouseButtons.h"

//���ļ����ڹ���һ������״̬��Ϣ������

//����ע��㣺1.���봰��Ӧ��Ҫʹ�÷�װ�õĴ��ڣ���WindowGL����Ϊ���ǵ��������е����Ĵ���ģ��ġ�2.����Ҫ�ֶ���������״̬����ΪGLFW�ṩ�첽��ȡ���������Զ�����

class InputStateManager
{
private:
    WindowGL* m_Window;  //Ŀ�괰�ڴ���

    //ʹ����������ƣ���Ϊ��ǰ״̬��һ��������״̬����Ҫ�ۺ���״̬���з���
    InputStateInfo m_OldStateInfo;  
    InputStateInfo m_NewStateInfo;
    InputStateInfo m_CurrentStateInfo;

public:
    InputStateManager(WindowGL* window);
    void SetWindow(WindowGL* window);  //����Ŀ�����
    void ClearState();  //���״̬�������ã�
    void UpdateState();  // ��ÿ֡���ã�����ˢ�� old/new ������ current

    //��ȡ˽�г�Ա�ӿ�
    const InputStateInfo& GetCurrentStateInfo();  //������ж���Ŀ�����ͬʱʹ��const�޶��ⲿ�޸�Ȩ��

};