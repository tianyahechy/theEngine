#include "feigeengine.h"
#include <Windows.h>
#include <gl/GL.h>
#include "core\include\common.h"

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

	this->render();
	
	_context.swapBuffer();

}

void feigeEngine::render()
{
	glColor4f (0.0, 0.0, 1.0, 0.5);
	float cx = 80;
	float cy = 100;
	float cz = 0;
	Pt3 thePt[4];
	thePt[0].x = 0;
	thePt[0].y = 0;
	thePt[0].z = cz;

	thePt[1].x = 0;
	thePt[1].y = 100;
	thePt[1].z = cz;

	thePt[2].x = 100;
	thePt[2].y = 0;
	thePt[2].z = cz;

	thePt[3].x = 100;
	thePt[3].y = 100;
	thePt[3].z = cz;

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, thePt);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4 );
}