#ifndef GLESRENDER_H
#define GLESRENDER
class Shader;
class GLESRender
{
public:
	GLESRender();
	~GLESRender();
	void init();
	void shutdown();
	void paint();
private:
	Shader* shader;
};
#endif // GLESRENDER
