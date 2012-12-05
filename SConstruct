import os
import sys

env = Environment()
env['CC'] = 'clang'
env['CXX'] = 'clang++'
env['CXXFLAGS'] = '-Weverything'
env['ENV']['TERM'] = os.environ['TERM']

gl_libs = []
if sys.platform != 'darwin':
	gl_libs = [ 'GL', 'GLU', 'glut', 'GLEW']
else:
	env.Append(FRAMEWORKS='OpenGL')	
	env.Append(FRAMEWORKS="GLUT")

env.Program('main', source=[ 'main.cpp', 'Shader.cpp'], LIBS=gl_libs )
