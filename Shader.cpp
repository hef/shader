#include "Shader.h"

#include <stdlib.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/glext.h>
#include <iostream>
#include <fstream>
#include <string>

Shader::Shader()
{

}

Shader::Shader( const char* vsFile, const char* fsFile )
{
	init( vsFile, fsFile );
}

Shader::~Shader()
{
	glDetachShader(shader_id, shader_fp);
	glDetachShader(shader_id, shader_fp);

	glDeleteShader(shader_fp);
	glDeleteShader(shader_vp);
	glDeleteProgram(shader_id);
}

void Shader::init( const char* vsFile, const char* fsFile )
{
	shader_vp = glCreateShader(GL_VERTEX_SHADER);
	shader_fp = glCreateShader(GL_FRAGMENT_SHADER);
	
	SetupShader(shader_vp, vsFile);
	SetupShader(shader_fp, fsFile);

	shader_id = glCreateProgram();
	glAttachShader(shader_id, shader_fp);
	glAttachShader(shader_id, shader_vp);
	glLinkProgram(shader_id);
}

void Shader::SetupShader( unsigned int shader_p, const char* filename )
{
	std::ifstream ifs(filename);
	std::string sText
	(
		(
			std::istreambuf_iterator<char>(ifs)
		),
			std::istreambuf_iterator<char>()
	);

	const char* text = sText.c_str();
	std::cout << sText << std::endl;

	glShaderSource(shader_p, 1, &text, 0);
	glCompileShader(shader_p);
}

void Shader::validateShader( unsigned int, const char* file /* = 0 */)
{
	const unsigned int BUFFER_SIZE = 512;
	char buffer[BUFFER_SIZE];
	//memset(buffer, 0, BUFFER_SIZE);

}

void Shader::Shader::bind()
{
	glUseProgram(shader_id);
}

void Shader::unbind()
{
	glUseProgram(0);
}

unsigned int Shader::id()
{
	return shader_id;
}
