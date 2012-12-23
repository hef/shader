#include "GLESRender.h"
#include "Shader.h"
//#include <GLES2/gl2.h>
#include <SDL/SDL_opengl.h>
//#include <GL/glew.h>

GLESRender::GLESRender()
{
	shader = new Shader();
}
GLESRender::~GLESRender()
{
	delete shader;
}
void GLESRender::init()
{
	shader->init("shader.vert", "shader.frag");

}
void GLESRender::shutdown()
{

}
void GLESRender::paint()
{

	//todo Move this
	GLfloat vVertices[] = {
		0.0f, 0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f
	};


	glViewport(0, 0, 640, 480);
	glClear(GL_COLOR_BUFFER_BIT);

	shader->bind();

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vVertices);
	glEnableVertexAttribArray(0);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	shader->unbind();

}
