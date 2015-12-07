#include "Shader_Manager.h"

using namespace Managers;

std::map<std::string, GLuint> Shader_Manager::programs;

Shader_Manager::Shader_Manager(){}

Shader_Manager::~Shader_Manager()
{
	std::map<std::string, GLuint>::iterator it;

	for (it = programs.begin(); it != programs.end(); it++)
	{
		GLuint prog = it->second;
		glDeleteProgram(prog);
	}
	programs.clear();
}

std::string Shader_Manager::ReadShader(const std::string &filename)
{
	std::string shaderCode;
	std::ifstream file(filename, std::ios::in); //open a file in var file

	if (!file.good())
	{
		std::cout << "Cannot open file: " << filename.c_str() << std::endl;
		std::terminate();
	}


	file.seekg(0, std::ios::end);	//go to end of stream
	shaderCode.resize((unsigned int)file.tellg());	//resize string to size of stream --> tellg() gives position on stream
	file.seekg(0, std::ios::beg);	//go back to beginning

	file.read(&shaderCode[0], shaderCode.size());	//read stream and copy into file
	file.close();

	return shaderCode;
}

GLuint Shader_Manager::CreateShader(GLenum shaderType, const std::string &source, const std::string &shaderName)
{
	int compile_result = 0;

	GLuint shader = glCreateShader(shaderType);	//creates empty shader
	const char *shader_code_ptr = source.c_str();	//get null terminated string (same string with '\0' at the end)
	const int shader_code_size = source.size();

	glShaderSource(shader, 1, &shader_code_ptr, &shader_code_size);	// it loads the shader object with the code
	glCompileShader(shader);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compile_result); //Check for errors and output them to the console

	if (compile_result == GL_FALSE)
	{
		int info_log_length = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &info_log_length);	//get info log length and save it to var
		std::vector<char> shader_log(info_log_length);	//all log messages
		glGetShaderInfoLog(shader, info_log_length, NULL, &shader_log[0]);
		std::cout << "Error compiling shader: " << shaderName.c_str() << std::endl << &shader_log[0] << std::endl;
		return 0;
	}

	return shader;
}

void Shader_Manager::CreateProgram(const std::string &shaderName, const std::string &vertexShaderFilename, const std::string &fragmentShaderFilename)
{
	std::string vertex_shader_code = ReadShader(vertexShaderFilename);
	std::string fragment_shader_code = ReadShader(fragmentShaderFilename);

	GLuint vertex_shader = CreateShader(GL_VERTEX_SHADER, vertex_shader_code, "vertex shader");
	GLuint fragment_shader = CreateShader(GL_FRAGMENT_SHADER, fragment_shader_code, "fragment shader");

	int link_result = 0;
	GLuint program = glCreateProgram();	//Create the program
	glAttachShader(program, vertex_shader);
	glAttachShader(program, fragment_shader);	//attach the shader to the program

	glLinkProgram(program);	//link the program
	glGetProgramiv(program, GL_LINK_STATUS, &link_result);	//check if linking was succesfull

	if (link_result == GL_FALSE)
	{
		//see logging above
		int info_log_length = 0;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &info_log_length);
		std::vector<char> program_log(info_log_length);
		glGetProgramInfoLog(program, info_log_length, NULL, &program_log[0]);
		std::cout << "Shader_Loader: LINK ERROR" << std::endl << &program_log[0] << std::endl;
		return;
	}
	//not checked if dhader already in map --> do that later
	programs[shaderName] = program;
}

const GLuint Shader_Manager::GetShader(const std::string &shaderName)
{
	//not checked if shader in map --> do that later
	return programs.at(shaderName);
}