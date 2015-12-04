#version 430 core	//version of OpenGL used

layout(location = 0) in vec3 in_position;	//set the frist input on location (index/pipt) 0 
											//--> glVertexAttribPointer(0,...) sets this pipe, glEnableVertexAttribArray(0) activates it in Code
layout(location = 1) in vec4 in_color;		//pipe 1 for color of vertex

out vec4 color;	//ouput the color to give to the fragment shader

void main()
{
	color = in_color;
	gl_Position = vec4(in_position, 1.0);	//w=1.0 for standard transformation in Normalized Device Coordinates(NDC) --> w=0.0 is the normal of the position
}