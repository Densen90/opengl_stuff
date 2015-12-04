#pragma once
#include "Core\Shader_Loader.h"
#include "Core\GameModels.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <vector>

Models::GameModels *gameModels;
GLuint program;

void renderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear buffer --> color and depth
	glClearColor(0.25, 0.8, 0.65, 1.0);

	glBindVertexArray(gameModels->GetModel("triangle1"));	//bind the VAO and draw the triangle
	glUseProgram(program);	//use the created program

	//draw 3 vertices as triangles
	glDrawArrays(GL_TRIANGLES, 0, 6);

	glutSwapBuffers();
	glutPostRedisplay();
}

void closeCallback()
{
	std::cout << "GLUT:\t Finished" << std::endl;
	glutLeaveMainLoop();
}

void init()
{
	char *versionText = glewIsSupported("GL_VERSION_4_5") ? "GLEW Version is 4.5" : "GLEW 4.5 is not supported";
	std::cout << versionText << std::endl;

	//do depth comparisons and update the depth buffer
	glEnable(GL_DEPTH_TEST);

	//initialize our game models
	gameModels = new Models::GameModels();
	gameModels->CreateTriangleModel("triangle1");

	//load and compile Shader
	Core::Shader_Loader shaderLoader;
	program = shaderLoader.CreateProgram("Shader\\vertex.glsl", "Shader\\fragment.glsl");

	// front- and back-facing polygons, GL_POINT, GL_LINE, or GL_FILL --> here, fill faces
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA); // window with a depth buffer | double buffered | RGBA Mode
	glutInitWindowPosition(500, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Drawing Triangles with shader");
	glewInit();
	
	init();

	glutDisplayFunc(renderScene);
	glutCloseFunc(closeCallback);

	glutMainLoop();

	delete gameModels;
	glDeleteProgram(program);
	return 0;
}

extern "C" {
	_declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
}