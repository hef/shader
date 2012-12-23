#ifndef EGLWINDOW_H
#define EGLWINDOW_H
#include <EGL/egl.h>


class EGLWindow
{
public:
	EGLWindow();
	bool init();
	bool shutdown();
	bool render();
private:
	EGLDisplay eglDisplay;
	EGLContext eglContext;
	EGLSurface eglSurface;

};

#endif // EGLWINDOW_H
