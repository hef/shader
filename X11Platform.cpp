#include "platform.h"
#include <assert.h>
#include <string.h>

#include <EGL/egl.h>
#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <X11/Xutil.h>

void* platform::getNativeWindow()
{
	Window root;
	XSetWindowAttributes swa;
	XSetWindowAttributes  xattr;
	Atom wm_state;
	XWMHints hints;
	XEvent xev;
	EGLConfig ecfg;
	EGLint num_config;
	Window win;

	Display* x_display = XOpenDisplay(NULL);
	assert(x_display);
 
     /*
      * X11 native display initialization
      */
 
     x_display = XOpenDisplay(NULL);
     if ( x_display == NULL )
     {
         return EGL_FALSE;
     }
 
     root = DefaultRootWindow(x_display);
 
     swa.event_mask  =  ExposureMask | PointerMotionMask | KeyPressMask;
     win = XCreateWindow(
                x_display, root,
                0, 0, 640, 480, 0,
                CopyFromParent, InputOutput,
                CopyFromParent, CWEventMask,
                &swa );
 
     xattr.override_redirect = false;
     XChangeWindowAttributes ( x_display, win, CWOverrideRedirect, &xattr );
 
     hints.input = true;
     hints.flags = InputHint;
     XSetWMHints(x_display, win, &hints);
 
     // make the window visible on the screen
     XMapWindow (x_display, win);
     XStoreName (x_display, win, "foo");
 
     // get identifiers for the provided atom name strings
     wm_state = XInternAtom (x_display, "_NET_WM_STATE", false);
 
     memset ( &xev, 0, sizeof(xev) );
     xev.type                 = ClientMessage;
     xev.xclient.window       = win;
     xev.xclient.message_type = wm_state;
     xev.xclient.format       = 32;
     xev.xclient.data.l[0]    = 1;
     xev.xclient.data.l[1]    = false;
     XSendEvent (
        x_display,
        DefaultRootWindow ( x_display ),
        false,
        SubstructureNotifyMask,
        &xev );
 
     //(eEGLNativeWindowType) win;
     return (void*) win;

}
