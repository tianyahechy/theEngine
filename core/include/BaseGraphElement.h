//所有绘制图元的基类，均继承于此类

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

	//绘制，每个子类必须实现它
	virtual void draw();// = 0;
};

