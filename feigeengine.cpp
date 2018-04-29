#include "feigeengine.h"

feigeEngine::feigeEngine(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	HWND theHWND = (HWND)winId();
	HDC theDC = ::GetDC(theHWND);
	_context.setup( theHWND, theDC);
}

feigeEngine::~feigeEngine()
{
	_context.shutdown();
}
void feigeEngine::paintEvent(QPaintEvent* evt)
{
	glClearColor(1, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	_context.swapBuffer();

	//paintEvent(0);
}
