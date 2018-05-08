#include "..\include\Triangle.h"

Triangle::Triangle(std::vector<Pt3> pointVec, std::vector<float> colorVec)
{
	_pointVec = pointVec;
	_colorVec = colorVec;
}

Triangle::~Triangle()
{
	_pointVec.clear();
}

void Triangle::draw()
{
	glBegin(GL_TRIANGLES);
	Pt3 p0 = _pointVec[0];
	Pt3 p1 = _pointVec[1];
	Pt3 p2 = _pointVec[2];

	float p0_x = p0.x;
	float p0_y = p0.y;
	float p0_z = p0.z;
	float p1_x = p1.x;
	float p1_y = p1.y;
	float p1_z = p1.z;
	float p2_x = p2.x;
	float p2_y = p2.y;
	float p2_z = p2.z;

	float r = _colorVec[0];
	float g = _colorVec[1];
	float b = _colorVec[2];
	float a = _colorVec[3];

	glColor4f(r,g,b,a);

	glVertex3f(p0_x, p0_y, p0_z);
	glVertex3f(p1_x, p1_y, p1_z);
	glVertex3f(p2_x, p2_y, p2_z);
	glEnd();
}