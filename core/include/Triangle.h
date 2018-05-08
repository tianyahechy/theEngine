#pragma once
#include "BaseGraphElement.h"
#include <vector>
class Triangle :
	public BaseGraphElement
{
public:
	Triangle(std::vector<Pt3> pointVec, std::vector<float> colorVec);
	~Triangle();

public:
	virtual void draw();

private:
	std::vector<Pt3> _pointVec;
	std::vector<float> _colorVec;
};

