#include "feigeengine.h"
#include <QtWidgets/QApplication>
#include "core\include\Line.h"
#include "core\include\Triangle.h"

void draw()
{
	Pt3 pt0;
	pt0.x = 0;
	pt0.y = 0;
	pt0.z = 0;
	Pt3 pt1;
	pt1.x = 100;
	pt1.y = 100;
	pt1.z = 0;
	Pt3 pt2;
	pt2.x = 50;
	pt2.y = 100;
	pt2.z = 0;
	std::vector<Pt3> pointVec;
	pointVec.clear();
	pointVec.push_back(pt0);
	pointVec.push_back(pt1);
	pointVec.push_back(pt2);

	float r = 0.0;
	float g = 0.5;
	float b = 0.5;
	float a = 0.5;
	std::vector<float> colorVec;
	colorVec.clear();
	colorVec.push_back(r);
	colorVec.push_back(g);
	colorVec.push_back(b);
	colorVec.push_back(a);

	BaseGraphElement *theTriangle = new Triangle(pointVec, colorVec);
	pointVec.clear();
	colorVec.clear();
	theTriangle->draw();

	typedef std::map<int, BaseGraphElement> mapGraphElement;
	typedef std::pair<int, BaseGraphElement> pairGraphElement;

	mapGraphElement renderList;
	renderList.clear();


	delete theTriangle;
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	feigeEngine w;

	//绘制内容
	w.p_MSG_Draw = draw;

	//设置摄像机参数
	int cameraLeft = w.geometry().x();
	int cameraRight = cameraLeft + w.geometry().width();
	int cameraBottom = w.geometry().height();
	int cameraTop = w.geometry().y();
	float cameraZNear = -100;
	float cameraZFar = 100;
	w.setCameraMatrixParameter(cameraLeft, cameraRight, cameraBottom, cameraTop, cameraZNear, cameraZFar);

	//设置投影参数
	int projX = w.geometry().x();
	int projY = w.geometry().y();
	int projWidth = w.geometry().width();
	int projHeight = w.geometry().height();
	w.setProjMatrixParameter(projX, projY, projWidth, projHeight);

	w.show();
	return a.exec();
}

