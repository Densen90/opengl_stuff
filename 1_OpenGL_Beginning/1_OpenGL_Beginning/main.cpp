#pragma once
#include "Core\Init\Init_GLUT.h"
#include "Managers\Scene_Manager.h"

using namespace Core;
using namespace Init;

int main(int argc, char **argv)
{
	WindowInfo window(std::string("Basic Game Engine: Dangine"),	//title
						800, 600,	//size
						400, 200,	//position
						true);	//resizable
	ContextInfo context(4, 5, true);	//core, version 4.5
	FrameBufferInfo fbi(true, true, true, true);	//color, depth, stencil, msaa

	Init_GLUT::Init(window, context, fbi);

	//Set our scene, our listener for drawings
	IListener *scene = new Managers::Scene_Manager();
	Init_GLUT::SetListener(scene);

	Init_GLUT::Run();

	//delete scene/listener before quitting
	delete scene;
	return 0;
}

extern "C" {
	_declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
}