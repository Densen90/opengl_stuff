/*
This structure keeps info about the OpenGL display mode
*/
#pragma once
#include "../../Dependencies/glew/glew.h"
#include "../../Dependencies/freeglut/freeglut.h"

namespace Core
{
	struct FrameBufferInfo
	{
		unsigned int flags;	//see some below
		bool msaa;	//Multisample Anti Aliasing
	
		FrameBufferInfo()
		{
			flags = GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA;
			msaa = false;
		}

		FrameBufferInfo(bool color, bool depth, bool stencil, bool msaa)
		{
			flags = GLUT_DOUBLE;	//must have

			if (color) flags |= GLUT_RGBA | GLUT_ALPHA;
			if (depth) flags |= GLUT_DEPTH;
			if (stencil) flags |= GLUT_STENCIL;
			if (msaa) flags |= GLUT_MULTISAMPLE;
			this->msaa = msaa;
		}

		FrameBufferInfo(FrameBufferInfo &fbi)
		{
			flags = fbi.flags;
			msaa = fbi.msaa;
		}

		void operator=(FrameBufferInfo &fbi)
		{
			flags = fbi.flags;
			msaa = fbi.msaa;
		}
	};
}

/*
GLUT_DEPTH to select a window with a depth buffer
GLUT_DOUBLE to select a double buffered window
GLUT_RGBA to select an RGBA mode window
GLUT_ALPHA tells OpenGL to add an alpha component to color buffer
GLUT_STENCIL tells OpenGL to add a stencil buffer. This buffer can store  per-pixel information.We can set a custom behavior based on this information in the rendering process.
GLUT_MULTISAMPLE tells OpenGL to create a window with multisampling support but doesn’t enable it. To enable it later you must call glEnable(GL_MULTISAMPLE).
*/