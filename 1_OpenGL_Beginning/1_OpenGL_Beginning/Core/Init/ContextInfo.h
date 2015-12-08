/*
Holding all the Information about the Context of our OpenGL (version, core or compatibility)
*/
#pragma once

namespace Core
{
	struct ContextInfo
	{
		int majorVersion;	// in Version X.Y --> majorVersion = X
		int minorVersion;	// in Version X.Y --> minorVersion = Y
		bool core;			// false = compatibility: want to have a higher GL version but still want to access deprecated methods from older versions
							// true = core: Lowering your version works only under Core context mode, otherwise freeglut sets it to highest possible

		ContextInfo()
		{
			majorVersion = 3;
			minorVersion = 3;
			core = true;
		}

		ContextInfo(int majorVersion, int minorVersion, bool core)
		{
			this->majorVersion = majorVersion;
			this->minorVersion = minorVersion;
			this->core = core;
		}

		ContextInfo(ContextInfo &contextInfo)
		{
			majorVersion = contextInfo.majorVersion;
			minorVersion = contextInfo.minorVersion;
			core = contextInfo.core;
		}

		void operator=(ContextInfo &contextInfo)
		{
			majorVersion = contextInfo.majorVersion;
			minorVersion = contextInfo.minorVersion;
			core = contextInfo.core;
		}
	};
}
