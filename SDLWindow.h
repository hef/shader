#ifndef SDLWINDOW_H
#define SDLWINDOW_H

struct SDL_Surface;

class SDLWindow
{
public:
	SDLWindow();
	bool init();
	bool shutdown();
	bool render();
private:
	SDL_Surface* surface;

};

#endif // SDLWINDOW_H
