#version 430 core

layout(location = 0) out vec4 out_color;	//framebuffer, In a double buffered rendering program, the color location is set on index 0

in vec4 color;	//from vertex shader

void main()
{
	out_color = color;
}