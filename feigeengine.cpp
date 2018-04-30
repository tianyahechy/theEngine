#include "feigeengine.h"

feigeEngine::feigeEngine(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//获取绘制窗口句柄和上下文
	HWND theHWND = (HWND)winId();
	HDC theDC = ::GetDC(theHWND);
	_context.setup( theHWND, theDC);
	//定时器间隔16毫秒
	_renderTimer.setInterval(16);
	_renderTimer.start();

	//投影范围
	_viewPort.x = this->geometry().x();
	_viewPort.y = this->geometry().y();
	_viewPort.width = this->geometry().width();
	_viewPort.height = this->geometry().height();
	
	//摄像机参数
	_camera.left = this->geometry().x();
	_camera.right = _camera.left + this->geometry().width();
	_camera.bottom = this->geometry().height();
	_camera.top = this->geometry().y();
	_camera.zNear = -100;
	_camera.zFar = 100;

	p_MSG_Draw = NULL;
	
	QObject::connect(&_renderTimer, SIGNAL(timeout()), this, SLOT(renderScene()));

}

feigeEngine::~feigeEngine()
{
	_context.shutdown();
	_renderTimer.stop();
}
//void feigeEngine::paintEvent(QPaintEvent* evt)
//{

	//paintEvent(0);
//}

void feigeEngine::renderScene()
{
	glClearColor(1, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	//指定当前矩阵是投影矩阵，开始操作投影矩阵
	glViewport(_viewPort.x, _viewPort.y, _viewPort.width, _viewPort.height);
	//将投影矩阵清空为单位矩阵
	glLoadIdentity();
	glOrtho(_camera.left, _camera.right, _camera.bottom, _camera.top, _camera.zNear, _camera.zFar);

	if (p_MSG_Draw)
	{
		(*p_MSG_Draw)();
	}
	
	_context.swapBuffer();

}