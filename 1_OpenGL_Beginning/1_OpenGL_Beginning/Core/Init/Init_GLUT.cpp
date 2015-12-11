#include "Init_GLUT.h"

using namespace Core::Init;

void Init_GLUT::Init(const Core::WindowInfo &windowInfo, const Core::ContextInfo &context, const Core::FrameBufferInfo &buffer)
{
	//we need fake arguements, because we are not in the main anymore
	int fargc = 1;
	char *fargv[] = { "f", NULL };
	glutInit(&fargc, fargv);

	//Initialize the Context Profile, Core: able to lower GL version, Compatibility: highest use of GL Version but able to use deprecated methods
	if (context.core)
	{
		glutInitContextVersion(context.majorVersion, context.minorVersion);
		glutInitContextProfile(GLUT_CORE_PROFILE);
	}
	else
	{
		glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);	//version doesn't matter in compatibility mode
	}

	//now init Glut
	glutInitDisplayMode(buffer.flags);
	glutInitWindowPosition(windowInfo.xPos, windowInfo.yPos);
	glutInitWindowSize(windowInfo.width, windowInfo.height);	// if we call those three functions after CreateWindow, it would have no effect
	glutCreateWindow(windowInfo.name.c_str());

	std::cout << "GLUT initialized" << std::endl;

	//set callbacks for rendering in GLUT
	glutIdleFunc(idleCallback);
	glutDisplayFunc(displayCallback);
	glutReshapeFunc(reshapeCallback);
	glutCloseFunc(closeCallback);

	//Initialize Glew
	Init_GLEW::Init();

	//set option for closing window -> immediately return from MainLoop
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	//now print the information of our created GLUT window
	printOpenGLInfo(windowInfo, context);
}

void Init_GLUT::Run()
{
	std::cout << "GLUT:\t Start Running" << std::endl;
	glutMainLoop();	//start Main Loop
}

void Init_GLUT::Close()
{
	std::cout << "GLUT:\t Exit" << std::endl;
	glutLeaveMainLoop();
}

void Init_GLUT::EnterFullscreen()
{
	glutFullScreen();
}

void Init_GLUT::ExitFullscreen()
{
	glutLeaveFullScreen();
}

void Init_GLUT::printOpenGLInfo(const Core::WindowInfo &windowInfo, const Core::ContextInfo &context)
{
	const unsigned char* renderer = glGetString(GL_RENDERER);
	const unsigned char* vendor = glGetString(GL_VENDOR);
	const unsigned char* version = glGetString(GL_VERSION);

	std::cout << std::endl << "*****************************************************************************" << std::endl;
	std::cout << "GLUT:\tVendor : " << vendor << std::endl;
	std::cout << "GLUT:\tRenderer : " << renderer << std::endl;
	std::cout << "GLUT:\tOpenGl version: " << version << std::endl;
	std::cout << "GLUT:\tInitial window is '" << windowInfo.name << std::endl; 
	std::cout << "GLUT:\tDimensions (" << windowInfo.width << "X" << windowInfo.height << ")" << std::endl;
	std::cout << "GLUT:\tPosition (" << windowInfo.xPos << "X" << windowInfo.yPos << ")" << std::endl;
	std::cout << "GLUT:\tWindow " << ((windowInfo.isReshapable) ? "is" : "is not ") << " resizable" << std::endl;
	std::cout << "GLUT:\tOpenGL context is " << context.majorVersion << "." << context.minorVersion;
	std::cout << "GLUT:\tProfile is " << ((context.core) ? "core" : "compatibility") << std::endl;
	std::cout << "*****************************************************************************" << std::endl << std::endl;
}


void Init_GLUT::idleCallback()
{
	//Just Redisplay in Idle to refresh the screen, Callback called when not receiving Window Events
	glutPostRedisplay();
}

void Init_GLUT::displayCallback()
{
	//called when window should be redisplayed, here called by glutPostRedisplay in idleFunc
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear buffer --> color and depth
	glClearColor(0, 0, 0, 1);
	glutSwapBuffers();
}

void Init_GLUT::reshapeCallback(int width, int height)
{

}

void Init_GLUT::closeCallback()
{
	Close();
}