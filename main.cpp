#include "feigeengine.h"
#include <QtWidgets/QApplication>

void draw()
{
	glBegin(GL_LINES);
	glVertex3f(0, 0, 0);
	glVertex3f(100, 100, 0);
	glEnd();
}
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	feigeEngine w;
	w.p_MSG_Draw = draw;
	w.show();
	return a.exec();
}

