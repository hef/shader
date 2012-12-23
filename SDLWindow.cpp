#include "SDLWindow.h"
#include <SDL.h>
#include <iostream>


SDLWindow::SDLWindow()
	: surface(NULL)
{
}
bool SDLWindow::init()
{
	int init = SDL_Init(SDL_INIT_VIDEO);
	if( init < 0 )
	{
		std::cout << "Unable to init SDL Video" << SDL_GetError();
		return false;
	}

	surface = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_GL_DOUBLEBUFFER | SDL_OPENGL);
	if( surface == NULL )
	{
		std::cout << "Unable set  SDL video mode" << SDL_GetError();
		return false;
	}
	return true;
}

bool SDLWindow::shutdown()
{
	SDL_FreeSurface(surface);
	return true;
}
bool SDLWindow::render()
{
	SDL_GL_SwapBuffers();
	return true;
}

