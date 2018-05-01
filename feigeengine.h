#ifndef FEIGEENGINE_H
#define FEIGEENGINE_H

#include <QtWidgets/QMainWindow>
#include "ui_feigeengine.h"
#include "core/include/GLContext.h"
#include <qtimer.h>

//ͶӰ���ڲ���
struct viewPortParameter
{
	int x;
	int y;
	int width;
	int height;
};

//��������ڲ���
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

public:
	//�������������
	void setCameraMatrixParameter(int left, int right, int bottom, int top, float zNear, float zFar);
	//����ͶӰ����
	void setProjMatrixParameter(int x, int y, int width, int height);

private:
	Ui::feigeEngineClass ui;

private:
	GLContext _context; //����������
	QTimer _renderTimer;//���ƶ�ʱ��
	viewPortParameter _viewPort;//ͶӰ����
	cameraParameter _camera; //�����

protected:
	//void paintEvent(QPaintEvent* evt);

	public slots:
	void renderScene();

public:
	//������ƺ���ָ��
	void(*p_MSG_Draw)();
};

#endif // FEIGEENGINE_H
