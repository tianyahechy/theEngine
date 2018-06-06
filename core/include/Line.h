
//线段
#pragma once
#include "common.h"
#include "BaseGraphElement.h"
class Line : public BaseGraphElement
{
public:
	Line( Pt3 startPt, Pt3 endPt );
	~Line();
	
private:
	Pt3 _startPt3;	//起始点
	Pt3 _endPt3;	//终点

public:
	virtual void draw();
};

