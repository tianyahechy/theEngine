#ifndef FEIGEENGINE_H
#define FEIGEENGINE_H

#include <QtWidgets/QMainWindow>
#include "ui_feigeengine.h"

class feigeEngine : public QMainWindow
{
	Q_OBJECT

public:
	feigeEngine(QWidget *parent = 0);
	~feigeEngine();

private:
	Ui::feigeEngineClass ui;
};

#endif // FEIGEENGINE_H
