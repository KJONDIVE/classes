#pragma once
#include "List.h"
#include "Event.h"
using namespace std;

class Dialog : public Vector
{
protected:
	int EndState;
public:
	Dialog();								//����������
	virtual ~Dialog(void);						//����������

	virtual void GetEvent(TEvent& event);		//�������� �������
	virtual int Execute();						//������� ���� ��������� �������
	virtual void HandleEvent(TEvent& event);	//����������
	virtual void ClearEvent(TEvent& event);		//�������� �������

	int Valid();								//�������� �������� EndState
	void EndExec();								//��������� ������� ������ �������
};

