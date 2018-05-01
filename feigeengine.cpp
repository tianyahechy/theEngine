#include "feigeengine.h"
#include <Windows.h>
#include <gl/GL.h>

feigeEngine::feigeEngine(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//��ȡ���ƴ��ھ����������
	HWND theHWND = (HWND)winId();
	HDC theDC = ::GetDC(theHWND);
	_context.setup( theHWND, theDC);
	//��ʱ�����16����
	_renderTimer.setInterval(16);
	_renderTimer.start();

	//����������ݳ�ʼ��Ϊ��
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
//����ͶӰ����
void feigeEngine::setProjMatrixParameter(int x, int y, int width, int height)
{
	//ͶӰ��Χ
	_viewPort.x = x;
	_viewPort.y = y;
	_viewPort.width = width;
	_viewPort.height = height;
}
//}

//����������������
void feigeEngine::setCameraMatrixParameter(int left, int right, int bottom, int top, float zNear, float zFar)
{
	//���������
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
	//ָ����ǰ������ͶӰ���󣬿�ʼ����ͶӰ����
	glViewport(_viewPort.x, _viewPort.y, _viewPort.width, _viewPort.height);
	//��ͶӰ�������Ϊ��λ����
	glLoadIdentity();
	glOrtho(_camera.left, _camera.right, _camera.bottom, _camera.top, _camera.zNear, _camera.zFar);

	if (p_MSG_Draw)
	{
		(*p_MSG_Draw)();
	}
	
	_context.swapBuffer();

}