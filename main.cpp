#include "Shader.h"
#if( (defined(__MACH__)) && (defined(__APPLE__)) )
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include <OpenGL/glext.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/glext.h>
#include <GL/glew.h>
#endif

Shader shader;
GLfloat angle = 0.0;


// light position variables
GLfloat lx = 0.0;
GLfloat ly = 1.0;
GLfloat lz = 1.0;
GLfloat lw = 0.0;

void init()
{
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	shader.init("shader.vert", "shader.frag");
}

void cube()
{
	glRotatef(angle, 1.0, 0.0, 0.0);
	glRotatef(angle, 0.0, 1.0, 0.0);
	glRotatef(angle, 0.0, 0.0, 1.0);

	GLfloat mShininess[] = {50};

	GLfloat DiffuseMaterial[] = {1.0, 0.0, 0.0};
	GLfloat AmbientMaterial[] = {0.0, 1.0, 0.0};
	GLfloat SpecularMaterial[] = {0.0, 0.0, 1.0};

	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, DiffuseMaterial);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, AmbientMaterial);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, SpecularMaterial);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mShininess);

	glutSolidTeapot(2.0);
}

void setLighting()
{
	GLfloat DiffuseLight[] = { 1.0, 1.0, 1.0 };
	GLfloat AmbientLight[] = { 0.2f, 0.2f, 0.2f };
	GLfloat SpecularLight[] = { 1.0, 1.0, 1.0 };

	glLightfv(GL_LIGHT0, GL_DIFFUSE, DiffuseLight);
	glLightfv(GL_LIGHT0, GL_AMBIENT, AmbientLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, AmbientLight);

	GLfloat LightPosition[] = { lx, ly, lz, lw };
	glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);
}

void display()
{
	glClearColor(0.0,0.0,0.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	setLighting();

	shader.bind();
	cube();
	shader.unbind();

	glutSwapBuffers();
	angle += 0.1f;
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, GLfloat(w)/GLfloat(h), 1.0, 100.0 );
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("A basic OpenGL Window");

#ifndef __APPLE__
	glewInit();
#endif
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutReshapeFunc(reshape);

	init();
	glutMainLoop();

	return 0;
}
