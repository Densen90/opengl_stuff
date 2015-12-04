#pragma once	//current source file to be included only once in a single compilation

#include "..\Dependencies\glew\glew.h"
#include "..\Dependencies\freeglut\freeglut.h"
#include "VertexFormat.h"
#include <vector>
#include <map>

namespace Models
{
	struct Model
	{
		unsigned int vao;	//vertex array object, keep track of multiple VBO --> id from OpenGL when binding vbos
		std::vector<unsigned int> vbos;	//vertex buffer objects, buffer for all the vertices

		Model(){}
	};

	class GameModels
	{
	public:
		GameModels();
		~GameModels();
		void CreateTriangleModel(const std::string &gameModelName);
		void DeleteModel(const std::string &gameModelName);
		unsigned int GetModel(const std::string &gameModelName);

	private:
		std::map<std::string, Model> GameModelList;	//Dictionary for the models
	};
};
