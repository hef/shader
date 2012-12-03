import os

env = Environment()
env['CC'] = 'clang'
env['CXX'] = 'clang++'
env['ENV']['TERM'] = os.environ['TERM']


env.Program('main', source=[ 'main.cpp', 'Shader.cpp'], LIBS=['GLEW', 'GL', 'GLU', 'glut'])
