//���л���ͼԪ�Ļ��࣬���̳��ڴ���

#pragma once

#include <Windows.h>
#include <gl\GL.h>

class BaseGraphElement
{
public:
	BaseGraphElement();
	~BaseGraphElement();

	//���ƣ�ÿ���������ʵ����
	virtual void draw();// = 0;
};

