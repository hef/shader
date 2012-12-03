#ifndef SHADER_H
#define SHADER_H
class Shader
{
public:
	Shader();
	Shader( const char* vsFile, const char* fsFile );
	~Shader();

	void init( const char* vsFile, const char* fsFile );

	void bind();
	void unbind();

	unsigned int id();

private:
	void SetupShader(unsigned int shader_p, const char* filename );
	void validateShader( unsigned int shader, const char* file = 0 );
	unsigned int shader_id;
	unsigned int shader_vp;
	unsigned int shader_fp;
};
#endif //Shader.h
