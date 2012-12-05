varying vec3 vertex_light_position;
varying vec3 vertex_normal;
void main()
{
	vertex_normal = normalize(gl_NormalMatrix * gl_Normal);
	vertex_light_position = normalize(gl_LightSource[0].position.xyz);
	gl_FrontColor = gl_Color;
	gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
}
