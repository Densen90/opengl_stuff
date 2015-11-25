#include "..\Dependencies\glew\glew.h"
#include "..\Dependencies\freeglut\freeglut.h"
#include <iostream>

void renderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear buffer --> color and depth
	glClearColor(0.25, 0.8, 0.65, 1.0);

	glutSwapBuffers();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA); // window with a depth buffer | double buffered | RGBA Mode
	glutInitWindowPosition(500, 500);
	glutInitWindowSize(800, 600);
	glutCreateWindow("First OpenGL Window");

	glewInit();
	char *versionText = glewIsSupported("GL_VERSION_4_5") ? "GLEW Version is 4.5" : "GLEW 4.5 is not supported";
	std::cout << versionText;

	glEnable(GL_DEPTH_TEST);

	glutDisplayFunc(renderScene);

	glutMainLoop();
	return 0;
}