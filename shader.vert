varying float diffuse_value;
void main()
{
	vec3 vertex_normal = normalize(gl_NormalMatrix * gl_Normal);
	vec3 vertex_light_position = gl_LightSource[0].position.xyz;
	diffuse_value = max( dot( vertex_normal, vertex_light_position ), 0.0 );
	gl_FrontColor = gl_Color;
	gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
}
