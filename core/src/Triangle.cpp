#include "..\include\Triangle.h"

Triangle::Triangle(std::vector<std::vector<Pt3>> pointVec, std::vector<float> colorVec)
{
	_pointVecVec = pointVec;
	_colorVec = colorVec;
}

Triangle::~Triangle()
{
	_pointVecVec.clear();
	_colorVec.clear();
}

void Triangle::draw()
{
	
	
	/*
	for (size_t i = 0; i < _pointVecVec.size(); i++)
	{
		std::vector<Pt3> theTriangle = _pointVecVec[i];
		Pt3 p0 = theTriangle[0];
		Pt3 p1 = theTriangle[1];
		Pt3 p2 = theTriangle[2];

		float p0_x = p0.x;
		float p0_y = p0.y;
		float p0_z = p0.z;
		float p1_x = p1.x;
		float p1_y = p1.y;
		float p1_z = p1.z;
		float p2_x = p2.x;
		float p2_y = p2.y;
		float p2_z = p2.z;

		glVertex3f(p0_x, p0_y, p0_z);
		glVertex3f(p1_x, p1_y, p1_z);
		glVertex3f(p2_x, p2_y, p2_z);

	}
	*/
	
}