#version 430 core

void main()
{
	//down,left corner: -1,-1   up,right corner: 1,1
	const vec4 vertices[3] = vec4[3](vec4(0.25, -0.25, 0.5, 1.0),	//x,y,z divided by fourth value for transformation, w=1.0, standard; w=0.0, normal
									vec4(-0.25, -0.25, 0.5, 1.0),
									vec4(0.25, 0.25, 0.5, 1.0));

	gl_Position = vertices[gl_VertexID];
}