#include "feigeengine.h"
#include <QtWidgets/QApplication>
#include "core\include\Line.h"

void draw()
{
	Pt3 startPt;
	startPt.x = 0;
	startPt.y = 0;
	startPt.z = 0;
	Pt3 endPt;
	endPt.x = 100;
	endPt.y = 100;
	endPt.z = 0;

	Line *theLine  = new Line(startPt, endPt);
	theLine->draw();

	delete theLine;
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

