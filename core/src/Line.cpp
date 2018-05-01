
#include "../include/Line.h"

Line::Line(Pt3 startPt3, Pt3 endPt3)
{
	_startPt3 = startPt3;
	_endPt3 = endPt3;
}

Line::~Line()
{

}

void Line::draw()
{
	glBegin(GL_LINES);
	double startX = _startPt3.x;
	double startY = _startPt3.y;
	double startZ = _startPt3.z;
	double endX = _endPt3.x;
	double endY = _endPt3.y;
	double endZ = _endPt3.z;
	glVertex3f(startX, startY, startZ);
	glVertex3f(endX, endY, endZ);
	glEnd();
}