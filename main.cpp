#include "Shader.h"
#include "glheader.h"
#include <iostream>

Shader shader;
GLfloat angle = 0.0;


// light position variables
GLfloat lx = 0.0;
GLfloat ly = 1.0;
GLfloat lz = 1.0;
GLfloat lw = 0.0;

void init()
{
	glClearColor(0,0,0,0);
	glViewport(0,0,640,480);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_TEXTURE_2D);
	glLoadIdentity();


	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	shader.init("shader.vert", "shader.frag");
}

void cube()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

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

	//glutSolidTeapot(2.0);
	glBegin(GL_QUADS);
		glColor3f(1,0,0); glVertex3f(0,0,0);
		glColor3f(1,1,0); glVertex3f(100,0,0);
		glColor3f(1,0,1); glVertex3f(100,100,0);
		glColor3f(1,1,1); glVertex3f(0,100,0);
	glEnd();
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
	//gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	setLighting();

	shader.bind();
	cube();
	shader.unbind();

	//glutSwapBuffers();
	SDL_GL_SwapBuffers();
	angle += 0.1f;
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluPerspective(60, GLfloat(w)/GLfloat(h), 1.0, 100.0 );
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char* argv[])
{
	//glutInit(&argc, argv);
	
	//glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
	//glutInitWindowSize(500,500);
	//glutInitWindowPosition(100,100);
	//glutCreateWindow("A basic OpenGL Window");
	
	SDL_Surface* screen;
	if(SDL_Init(SDL_INIT_VIDEO) != 0)
		std::cout << "SDL Video: " << SDL_GetError() << std::endl;
	screen = SDL_SetVideoMode(640,480,32,SDL_OPENGL);
	if( !screen )
		std::cout << "SDL Set Video Mode: " << SDL_GetError() << std::endl;

	
#if USE_GLEW
	GLenum glewError = glewInit();
	std::cout << glewGetErrorString(glewError) << std::endl;
#endif

	//glutDisplayFunc(display);
	//glutIdleFunc(display);
	//glutReshapeFunc(reshape)
	

	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return false;

	init();
	//glutMainLoop();
	
	while(true)
	{
		display();
	}

	return 0;
}
