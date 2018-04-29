#include "feigeengine.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	feigeEngine w;
	w.show();
	return a.exec();
}

