//���л���ͼԪ�Ļ��࣬���̳��ڴ���

#pragma once

#include <Windows.h>
#include <gl\GL.h>

struct Pt3
{
	double x;
	double y;
	double z;
};
class BaseGraphElement
{
public:
	BaseGraphElement();
	~BaseGraphElement();

	//���ƣ�ÿ���������ʵ����
	virtual void draw();// = 0;
};

