#pragma once

//Listener for Listening of new drawing calls
namespace Core
{
	class IListener
	{
	public:
		virtual ~IListener() = 0;

		//drawing functions, called in the displayCallback() method from Init_GLUT class
		//splitted because then we have a good flow in the rendering loop
		//to better split the CPU commands (Physics, AI etc.) from the GPU(rendering) stuff
		//example: physics and collission at beginning of each frame in notifyBeginFrame(), 
		//and after that we can draw everything in notifyDisplayFrame() and do other stuff in notifyEndFrame()
		virtual void notifyBeginFrame() = 0;
		virtual void notifyDisplayFrame() = 0;
		virtual void notifyEndFrame() = 0;
		virtual void notifyReshape(int width, int height, int previousWidth, int previousHeight) = 0;
	};

	inline IListener::~IListener(){}
}