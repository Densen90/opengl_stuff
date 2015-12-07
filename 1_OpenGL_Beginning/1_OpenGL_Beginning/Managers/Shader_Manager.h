#pragma once

#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include "..\Dependencies\glew\glew.h"
#include "..\Dependencies\freeglut\freeglut.h"

namespace Managers
{
	class Shader_Manager
	{
	public:
		Shader_Manager();
		~Shader_Manager();
		void CreateProgram(const std::string &shaderName, const std::string &vertexShaderFilename, const std::string &fragmentShaderFilename);

		static const GLuint GetShader(const std::string &shaderName);	//can be called without having an instace of the Shader_Manager -> can only use static variables, because they exist also when there is no instance of the class

	private:
			std::string ReadShader(const std::string &filename);
			GLuint CreateShader(GLenum shaderType, const std::string &source, const std::string &shaderName);
			static std::map<std::string, GLuint> programs;	//is the same / shared by every instace of the class --> multiple shader manager have the same map
	};
};
