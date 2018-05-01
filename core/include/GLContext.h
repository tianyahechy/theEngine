
//�����豸�����������

#pragma once
#include <Windows.h>
#include <gl/gl.h>

class   GLContext
{
protected:
    int         _format;
    //! ���ھ��
    HWND        _hWnd;
    //! �����豸������
    HDC         _hDC;
    //! OpenGL������
    HGLRC       _hRC;
public:
	GLContext();
	~GLContext();
    /**
    *   ��ʼ��GL
    */
	bool setup(HWND hWnd, HDC hDC);

    /**
    *   ����EGL
    */
	void shutdown();

    /**
    *   ����������
    */
	void swapBuffer();
};
