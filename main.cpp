#include "../core/include/common.h"
#include "feigeengine.h"
#include <QtWidgets/QApplication>
#include "core\include\Line.h"
#include "core\include\Triangle.h"

void draw()
{
	std::vector<std::vector<Pt3>> pointVecVec;
	pointVecVec.clear();
	float cx = 100;
	float cy = 100;
	float cz = 0;
	float radius = 80.0;
	for (size_t j = 0; j < 360; j=j+2)
	{
		std::vector<Pt3> pointVec;
		pointVec.clear();
		Pt3 pt0;
		pt0.x = cx;
		pt0.y = cy;
		pt0.z = cz;
		pointVec.push_back(pt0);
		for (size_t i = 0; i < 2; i++)
		{
			float x = (float)cos((i+j) *3.1415926 / 180) * radius + cx;
			float y = (float)sin((i+j)* 1.0* 3.1415926 / 180) * radius + cy;
			float z = cz;
			Pt3 thePt;
			thePt.x = x;
			thePt.y = y;
			thePt.z = z;
			pointVec.push_back(thePt);
		}

		pointVecVec.push_back(pointVec);
		pointVec.clear();
	}
	
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

	for (size_t i = 0; i < pointVecVec.size(); i++)
	{
		
		BaseGraphElement *theTriangle = new Triangle(pointVecVec[i], colorVec);
		pointVecVec[i].clear();
		pointVecVec[i].clear();
		theTriangle->draw();

		delete theTriangle;
	}

	typedef std::map<int, BaseGraphElement> mapGraphElement;
	typedef std::pair<int, BaseGraphElement> pairGraphElement;

	mapGraphElement renderList;
	renderList.clear();

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

