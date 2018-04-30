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
