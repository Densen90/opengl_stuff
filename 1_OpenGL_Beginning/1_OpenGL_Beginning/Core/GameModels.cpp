#include "GameModels.h"

using namespace Models;

GameModels::GameModels(){}

GameModels::~GameModels()
{
	std::map<std::string, Model>::iterator it;

	for (it = GameModelList.begin(); it != GameModelList.end(); it++)
	{
		//delete all VBO and VAO
		unsigned int *vao = &it->second.vao;
		glDeleteVertexArrays(it->second.vbos.size(), vao);
		glDeleteBuffers(it->second.vbos.size(), &it->second.vbos[0]);
		it->second.vbos.clear();
	}
	GameModelList.clear();
}

void GameModels::CreateTriangleModel(const std::string &gameModelName)
{
	unsigned int vbo;
	unsigned int vao;	//vao and vbo handler

	glGenVertexArrays(1, &vao);	//create VAO container and get ID for it
	glBindVertexArray(vao);	//bind to OpenGL context

	std::vector<VertexFormat> vertices;	//all vertices used
	vertices.push_back(VertexFormat(glm::vec3(0.25, -0.25, 0.0),	//position
									glm::vec4(1.0, 0.0, 0.0, 1.0)));		//color
	vertices.push_back(VertexFormat(glm::vec3(-0.25, -0.25, 0.0),
									glm::vec4(0.0, 1.0, 0.0, 1.0)));
	vertices.push_back(VertexFormat(glm::vec3(0.25, 0.25, 0.0),
									glm::vec4(0.0, 0.0, 1.0, 1.0)));
	vertices.push_back(VertexFormat(glm::vec3(0.5, -0.25, 0.0),
									glm::vec4(1.0, 0.0, 0.0, 1.0)));
	vertices.push_back(VertexFormat(glm::vec3(0.75, -0.25, 0.0),
									glm::vec4(0.0, 1.0, 0.0, 1.0)));
	vertices.push_back(VertexFormat(glm::vec3(0.5, 0.25, 0.0),
									glm::vec4(0.0, 0.0, 1.0, 1.0)));

	glGenBuffers(1, &vbo);	//generate VBO container and get ID for it
	glBindBuffer(GL_ARRAY_BUFFER, vbo);	//bind to context
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexFormat) * vertices.size(), &vertices[0], GL_STATIC_DRAW);	//allocate memory at binding point for all vertices

	glEnableVertexAttribArray(0);	//activate pipe 0 to vertex shader
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)0);	//pipe 0, send 3 values for position (x,y,z), send floats, send non normalized, next vertex appears after sizeof(VertexFormat), offset 0
	glEnableVertexAttribArray(1);	//activate pipe 1
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)12);	//pipe 1, 4 vlaues for color (rgba), offset 12 --> appears 12 byte after position in memory, 4 byte per position value(x,y,z)

	Model myModel;	//allocated on stack
	myModel.vao = vao;
	myModel.vbos.push_back(vbo);	//add vbo, more vbos possible
	GameModelList[gameModelName] = myModel;
}

void GameModels::DeleteModel(const std::string &gameModelName)
{
	Model myModel = GameModelList[gameModelName];
	unsigned int vao = myModel.vao;
	glDeleteVertexArrays(myModel.vbos.size(), &vao);
	glDeleteBuffers(myModel.vbos.size(), &myModel.vbos[0]);
	myModel.vbos.clear();
	GameModelList.erase(gameModelName);
}

unsigned int GameModels::GetModel(const std::string &gameModelName)
{
	return GameModelList[gameModelName].vao;
}