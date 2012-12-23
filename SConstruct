import os
import sys

env = Environment()
env['CC'] = 'clang'
env['CXX'] = 'clang++'
env.Append(CXXFLAGS = ['-g', '-std=c++11'])
env['ENV']['TERM'] = os.environ['TERM']


pc = env.Clone()
pc.VariantDir('pc', '.')
pc.ParseConfig('sdl-config --cflags --libs')
pc.Append(LIBS=["GL"])
pc.Append(LIBS=["GLEW"])
pc.Append(LIBS=["X11"])
pc.Append(LIBS=["EGL"])
#pc.Program('main', source=[ 'pc/main.cpp', 'pc/Shader.cpp'])
pc.Program('sdlmain', source=[ 'pc/sdlmain.cpp', 'pc/Shader.cpp', 'pc/SDLWindow.cpp', 'pc/SDLInput.cpp', 'pc/GLESRender.cpp'])
pc.Program('eglmain', source=[ 'pc/eglmain.cpp', 'pc/Shader.cpp', 'pc/EGLWindow.cpp', 'pc/SDLInput.cpp', 'pc/GLESRender.cpp', 'pc/X11Platform.cpp'])


web = env.Clone()
web.VariantDir('web', '.')
web['CC'] = '/home/hef/projects/emscripten/emcc'
web['CXX'] = '/home/hef/projects/emscripten/em++'
web['LINKFLAGS'].append(['--preload-file', 'shader.vert'])
web['LINKFLAGS'].append(['--preload-file', 'shader.frag'])
#web.Program('main.html', source=[ 'web/main.cpp', 'web/Shader.cpp'])
#web.Program('sdlmain.html', source=[ 'web/main2.cpp', 'web/Shader.cpp', 'web/SDLWindow.cpp', 'web/SDLInput.cpp', 'web/GLESRender.cpp'])
web.Program('eglmain.html', source=[ 'web/eglmain.cpp', 'web/Shader.cpp', 'web/EGLWindow.cpp', 'web/SDLInput.cpp', 'web/GLESRender.cpp', 'web/WebPlatform.cpp'])
web.Program('sdlmain.html', source=[ 'web/sdlmain.cpp', 'web/Shader.cpp', 'web/EGLWindow.cpp', 'web/SDLInput.cpp', 'web/GLESRender.cpp', 'web/WebPlatform.cpp'])

