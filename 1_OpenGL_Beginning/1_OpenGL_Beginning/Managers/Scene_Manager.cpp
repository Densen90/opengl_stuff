#include "Scene_Manager.h"

using namespace Managers;

Scene_Manager::Scene_Manager()
{
	glEnable(GL_DEPTH_TEST);

	shaderManager = new Shader_Manager();
	shaderManager->CreateProgram("colorShader", "Shader\\vertex.glsl", "Shader\\fragment.glsl");
}

Scene_Manager::~Scene_Manager()
{
	delete shaderManager;
}

void Scene_Manager::notifyBeginFrame()
{
	//till now no calculations here
}

void Scene_Manager::notifyDisplayFrame()
{
	//called when window should be redisplayed, here called by glutPostRedisplay in idleFunc
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear buffer --> color and depth
	glClearColor(0, 0, 0, 1);
}

void Scene_Manager::notifyEndFrame()
{
	//nothing to do here now
}

void Scene_Manager::notifyReshape(int width, int height, int previousWidth, int previousHeight)
{
	//nothing to do here now
}