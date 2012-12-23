#include "SDLInput.h"
#include <SDL.h>


SDLInput::SDLInput()
{

}
bool SDLInput::init()
{
	return true;
}
bool SDLInput::shutdown()
{
	return true;
}

void SDLInput::onExit( const std::function<void(void)>& exit )
{
	exits.push_back(exit);
		
}
bool SDLInput::handleInput()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch(event.type)
	{
	case SDL_QUIT:
		for( auto i: exits)
			i();
		break;

	default:
		break;

	}
	return true;

}

