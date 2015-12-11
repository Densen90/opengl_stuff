#pragma once
#include "ContextInfo.h"
#include "FrameBufferInfo.h"
#include "WindowInfo.h"
#include "Init_GLEW.h"
#include <iostream>

namespace Core
{
	namespace Init
	{
		class Init_GLUT	//static methods because global visibility, to call them without having an instance of the class
		{
		public:
			static void Init(const Core::WindowInfo &windowInfo,	//Init with created sctructs
							 const Core::ContextInfo &context,
							 const Core::FrameBufferInfo &buffer);

			//called from the outside
			static void Run();
			static void Close();

			void EnterFullscreen();
			void ExitFullscreen();

			//used to print info about OpenGL
			static void printOpenGLInfo(const Core::WindowInfo &windowInfo, const Core::ContextInfo &context);

		private:
			static void idleCallback();
			static void displayCallback();
			static void reshapeCallback(int width, int height);
			static void closeCallback();
		};
	}
}
