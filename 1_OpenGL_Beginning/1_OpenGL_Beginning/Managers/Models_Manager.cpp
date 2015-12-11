#include "Models_Manager.h"

using namespace Managers;
using namespace Rendering;

Models_Manager::Models_Manager()
{
	//set up our triangle object
	Models::Triangle *triangle = new Models::Triangle;
	triangle->SetProgram(Shader_Manager::GetShader("colorShader"));
	triangle->Create();
	gameModelList["triangle"] = triangle;
}

Models_Manager::~Models_Manager()
{
	//auto -it's a map iterator
	for (auto model : gameModelList)
	{
		delete model.second;
	}
	gameModelList.clear();
}

void Models_Manager::Draw()
{
	//auto -it's a map iterator
	for (auto model : gameModelList)
	{
		model.second->Draw();
	}
}

void Models_Manager::Update()
{
	//auto -it's a map iterator
	for (auto model : gameModelList)
	{
		model.second->Update();
	}
}

void Models_Manager::DeleteModel(const std::string &gameModelName)
{
	//normal: check if existant
	IGameObject *model = gameModelList[gameModelName];
	model->Destroy();
	gameModelList.erase(gameModelName);
}

const IGameObject &Models_Manager::GetModel(const std::string &gameModelName) const
{
	return *gameModelList.at(gameModelName);
}