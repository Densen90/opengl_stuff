#include "Triangle.h"

using namespace Rendering;
using namespace Models;

Triangle::Triangle() {}

Triangle::~Triangle() {}	//nothing to do here, dleted in Model.cpp -> inheritance

void Triangle::Create()
{
	GLuint vbo;
	GLuint vao;	//vao and vbo handler

	glGenVertexArrays(1, &vao);	//create VAO container and get ID for it
	glBindVertexArray(vao);	//bind to OpenGL context

	std::vector<VertexFormat> vertices;	//all vertices used
	vertices.push_back(VertexFormat(glm::vec3(0.25, -0.25, 0.0),			//position
									glm::vec4(1.0, 0.0, 0.0, 1.0)));		//color
	vertices.push_back(VertexFormat(glm::vec3(-0.25, -0.25, 0.0),
									glm::vec4(0.0, 1.0, 0.0, 1.0)));
	vertices.push_back(VertexFormat(glm::vec3(0.25, 0.25, 0.0),
									glm::vec4(0.0, 0.0, 1.0, 1.0)));

	glGenBuffers(1, &vbo);	//generate VBO container and get ID for it
	glBindBuffer(GL_ARRAY_BUFFER, vbo);	//bind to context
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexFormat) * vertices.size(), &vertices[0], GL_STATIC_DRAW);	//allocate memory at binding point for all vertices

	glEnableVertexAttribArray(0);	//activate pipe 0 to vertex shader
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)0);	//pipe 0, send 3 values for position (x,y,z), send floats, send non normalized, next vertex appears after sizeof(VertexFormat), offset 0
	glEnableVertexAttribArray(1);	//activate pipe 1
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(offsetof(VertexFormat, VertexFormat::color)));	//pipe 1, 4 vlaues for color (rgba), offset 12 --> appears 12 byte after position in memory, 4 byte per position value(x,y,z), calculated dynamically

	//assign the values to our model
	this->vao = vao;
	this->vbos.push_back(vbo);	//add vbo, more vbos possible
}

void Triangle::Draw()
{
	glUseProgram(this->program);
	glBindVertexArray(this->vao);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Triangle::Update()
{
	//nothing to update for now in the triangle
}