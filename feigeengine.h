#ifndef FEIGEENGINE_H
#define FEIGEENGINE_H

#include <QtWidgets/QMainWindow>
#include "ui_feigeengine.h"
#include "core/include/GLContext.h"
#include <qtimer.h>

//投影窗口参数
struct viewPortParameter
{
	int x;
	int y;
	int width;
	int height;
};

//摄像机窗口参数
struct cameraParameter
{
	int left;
	int right;
	int bottom;
	int top;
	int zNear;
	int zFar;
};
class feigeEngine : public QMainWindow
{
	Q_OBJECT

public:
	feigeEngine(QWidget *parent = 0);
	~feigeEngine();

private:
	Ui::feigeEngineClass ui;

private:
	GLContext _context; //绘制上下文
	QTimer _renderTimer;//绘制定时器
	viewPortParameter _viewPort;//投影窗口
	cameraParameter _camera; //摄像机

protected:
	//void paintEvent(QPaintEvent* evt);

	public slots:
	void renderScene();

public:
	//具体绘制函数指针
	void(*p_MSG_Draw)();
};

#endif // FEIGEENGINE_H
