#include "EGLWindow.h"
#include <EGL/egl.h>
#include <iostream>
#include <assert.h>
#include "platform.h"


EGLWindow::EGLWindow()
{
}
bool EGLWindow::init()
{
	
	EGLint attribList[] =
	{
		EGL_RED_SIZE, 		5,
		EGL_GREEN_SIZE,		6,
		EGL_BLUE_SIZE, 		5,
		EGL_NONE
	};

	EGLint contextAttribs[] =
	{
		EGL_CONTEXT_CLIENT_VERSION, 	2,
		EGL_NONE, 			EGL_NONE
	};

	EGLint numConfigs;
	EGLConfig config;

	EGLBoolean result = false;

	eglDisplay = eglGetDisplay(EGL_DEFAULT_DISPLAY);
	assert( EGL_NO_DISPLAY != eglDisplay );

	EGLint major;
	EGLint minor;
	result = eglInitialize(eglDisplay, &major, &minor);
	assert(result);

	result = eglGetConfigs(eglDisplay, NULL, 0, &numConfigs);
	assert(result);

	result = eglChooseConfig(eglDisplay, attribList, &config, 1, &numConfigs );
	assert(result);

	// Platform specific stuff
	void* nativeWindow = platform::getNativeWindow();

	
	//TODO create platform specific EGL NativeWindowType
	eglSurface = eglCreateWindowSurface( eglDisplay, config, (NativeWindowType) nativeWindow, NULL);
	assert( EGL_NO_SURFACE != eglSurface );

	eglContext = eglCreateContext(eglDisplay, config, EGL_NO_CONTEXT, contextAttribs);
	assert(EGL_NO_CONTEXT != eglContext);

	result = eglMakeCurrent(eglDisplay, eglSurface, eglSurface, eglContext);
	assert(result);



       	return true;
}

bool EGLWindow::shutdown()
{
	return true;
}
bool EGLWindow::render()
{
	eglSwapBuffers(eglDisplay, eglSurface);
	return true;
}

