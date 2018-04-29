#ifndef FEIGEENGINE_H
#define FEIGEENGINE_H

#include <QtWidgets/QMainWindow>
#include "ui_feigeengine.h"
#include "core/include/GLContext.h"
#include <qtimer.h>

class feigeEngine : public QMainWindow
{
	Q_OBJECT

public:
	feigeEngine(QWidget *parent = 0);
	~feigeEngine();

private:
	Ui::feigeEngineClass ui;

private:
	GLContext _context;

protected:
	void paintEvent(QPaintEvent* evt);
};

#endif // FEIGEENGINE_H
