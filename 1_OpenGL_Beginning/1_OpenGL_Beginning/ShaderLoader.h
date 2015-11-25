#pragma once

#include "..\Dependencies\glew\glew.h"
#include "..\Dependencies\freeglut\freeglut.h"
#include <iostream>

namespace Core
{
	class Shader_Loader
	{
		private:
			std::string ReadShader(char* filename);
			GLuint CreateShader(GLenum shaderType, std::string source, char* shaderName);

		public:
			Shader_Loader();
			~Shader_Loader();
			GLuint CreateProgram(char* VertexShaderFilename, char* FragmentShaderFilename);
	};
};
