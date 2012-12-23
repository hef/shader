#include "SDLWindow.h"
#include "SDLInput.h"
#include "GLESRender.h"
#include <iostream>
#include <SDL.h>
#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif

void loop_body();

SDLWindow window;
GLESRender render;
SDLInput input;
int frame = 0;


int main()
{
	std::cout << "Pre window init" << std::endl;
	window.init();

	std::cout << "Pre render init" << std::endl;
	render.init();

	input.init();
	bool shouldExit = false;
	input.onExit([&shouldExit](){shouldExit=true;});

	std::cout << "pre loop" << std::endl;

#ifdef EMSCRIPTEN
	emscripten_set_main_loop(loop_body, 15, true);
#else
	while( !shouldExit)
	{
		loop_body();
	}
#endif // EMSCRIPTEN
	return 0;

}

void loop_body()
{
	input.handleInput();
	render.paint();
	window.render();
	std::cout << "frame: " << ++frame << std::endl;
	
}
