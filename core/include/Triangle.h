#pragma once
#include "BaseGraphElement.h"
#include <vector>
#include "common.h"
class Triangle :
	public BaseGraphElement
{
public:
	Triangle(std::vector<std::vector<Pt3>> pointVec, std::vector<float> colorVec);
	~Triangle();

public:
	virtual void draw();

private:
	std::vector<std::vector<Pt3>> _pointVecVec;
	std::vector<float> _colorVec;
};

