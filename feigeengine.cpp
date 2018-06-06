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
	float cx = 100;
	float cy = 80;
	float cz = 0;
	float radius = 80;
	Pt3 thePt[360*3];
	for (size_t i = 0; i < 360; i++)
	{
		thePt[i * 3 + 0].x = cx;
		thePt[i * 3 + 0].y = cy;
		thePt[i * 3 + 0].z = cz;
		thePt[i * 3 + 1].x = cx + cos(i*M_PI/180) * radius;
		thePt[i * 3 + 1].y = cy + sin(i* M_PI/180) * radius;
		thePt[i * 3 + 1].z = cz;
		thePt[i * 3 + 2].x = cx + cos((i+1)*M_PI / 180) * radius;
		thePt[i * 3 + 2].y = cy + sin((i+1)* M_PI / 180) * radius;
		thePt[i * 3 + 2].z = cz;
	}
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, thePt);
	glDrawArrays(GL_TRIANGLES, 0, 360 * 3);
}