#include "../core/include/common.h"
#include "feigeengine.h"
#include <QtWidgets/QApplication>
#include "core\include\Line.h"
#include "core\include\Triangle.h"

void draw()
{

	typedef std::map<int, BaseGraphElement> mapGraphElement;
	typedef std::pair<int, BaseGraphElement> pairGraphElement;

	mapGraphElement renderList;
	renderList.clear();

}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	feigeEngine w;

	//�������������
	int cameraLeft = w.geometry().x();
	int cameraRight = cameraLeft + w.geometry().width();
	int cameraBottom = w.geometry().height();
	int cameraTop = w.geometry().y();
	float cameraZNear = -100;
	float cameraZFar = 100;
	w.setCameraMatrixParameter(cameraLeft, cameraRight, cameraBottom, cameraTop, cameraZNear, cameraZFar);

	//����ͶӰ����
	int projX = w.geometry().x();
	int projY = w.geometry().y();
	int projWidth = w.geometry().width();
	int projHeight = w.geometry().height();
	w.setProjMatrixParameter(projX, projY, projWidth, projHeight);

	//��������
	w.p_MSG_Draw = draw;
	w.show();

	return a.exec();
}

