/*
Holding all the Information about our opened Window
*/
#pragma once
#include <string>

namespace Core
{
	struct WindowInfo
	{
		std::string name;
		int width, height;
		int xPos, yPos;
		bool isReshapable;

		//Standard Window
		WindowInfo()
		{
			name = "OpenGL - Basic Engine";
			width = 800;
			height = 600;
			x_pos = 300;
			y_pos = 300;
		}

		//specific window
		WindowInfo(std::string name, int width, int height, int xPos, int yPos, bool isReshapable)
		{
			this->name = name;
			this->width = width;
			this->height = height;
			this->xPos = xPos;
			this->yPos = yPos;
			this->isReshapable = isReshapable;
		}

		//copy constructor
		WindowInfo(const WindowInfo &windowInfo)
		{
			name = windowInfo.name;
			width = windowInfo.width;
			height = windowInfo.height;
			xPos = windowInfo.xPos;
			yPos = windowInfo.yPos;
			isReshapable = windowInfo.isReshapable;
		}

		//overriding = operator
		void operator=(const WindowInfo &windowInfo)
		{
			name = windowInfo.name;
			width = windowInfo.width;
			height = windowInfo.height;
			xPos = windowInfo.xPos;
			yPos = windowInfo.yPos;
			isReshapable = windowInfo.isReshapable;
		}
	};
}
