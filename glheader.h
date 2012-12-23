#if !EMSCRIPTEN
#define USE_GLEW 1
#endif

#if USE_GLEW
#include "GL/glew.h"
#endif

#define NO_SDL_GLEXT
#include <SDL/SDL.h>
#include "SDL/SDL_opengl.h"

