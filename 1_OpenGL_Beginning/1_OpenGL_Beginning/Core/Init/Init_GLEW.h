/*
For initializing GLEW
*/
#pragma once
#include <iostream>
#include "../../Dependencies/glew/glew.h"
#include "../../Dependencies/freeglut/freeglut.h"

namespace Core
{
	namespace Init
	{
		class Init_GLEW
		{
		public:
			static void Init();
		};
	}
}