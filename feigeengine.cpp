#include "feigeengine.h"
#include <Windows.h>
#include <gl/GL.h>
#include "core\include\common.h"

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

	//具体绘制内容初始化为空
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

	//paint
//设置投影矩阵
void feigeEngine::setProjMatrixParameter(int x, int y, int width, int height)
{
	//投影范围
	_viewPort.x = x;
	_viewPort.y = y;
	_viewPort.width = width;
	_viewPort.height = height;
}
//}

//设置摄像机矩阵参数
void feigeEngine::setCameraMatrixParameter(int left, int right, int bottom, int top, float zNear, float zFar)
{
	//摄像机参数
	_camera.left = this->geometry().x();
	_camera.right = _camera.left + this->geometry().width();
	_camera.bottom = this->geometry().height();
	_camera.top = this->geometry().y();
	_camera.zNear = -100;
	_camera.zFar = 100;

}

void feigeEngine::renderScene()
{
	glClearColor(1, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	//指定当前矩阵是投影矩阵，开始操作投影矩阵
	glViewport(_viewPort.x, _viewPort.y, _viewPort.width, _viewPort.height);
	//将投影矩阵清空为单位矩阵
	glLoadIdentity();
	glOrtho(_camera.left, _camera.right, _camera.bottom, _camera.top, _camera.zNear, _camera.zFar);

	this->render();
	
	_context.swapBuffer();

}

void feigeEngine::render()
{
	glColor4f (0.0, 0.0, 1.0, 0.5);
	Pt3 rect[] =
	{
		{ 10, 10, 0, 1, 0, 0, 0.5 },
		{ 110, 10, 0, 0, 0.5, 0, 0.5 },
		{ 110, 110, 0, 1, 0, 0.5, 0.5 },
		{ 10, 110, 0, 0, 0, 0.5, 0.5 }
	};

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, sizeof(Pt3), rect);
	glColorPointer(4, GL_FLOAT, sizeof(Pt3), &rect[0].red);
	glDrawArrays(GL_LINE_LOOP, 1, 3 );
}