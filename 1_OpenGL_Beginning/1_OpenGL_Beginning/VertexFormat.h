#ifndef VertexFormat_H_	//Hier überprüft der Präprozessor, ob er die Headerdatei "VertexFormat.h" noch nicht eingebunden hat. So wird sie maximal einmal eingebunden
#define VertexFormat_H_
#pragma once

#include "glm\glm.hpp"	//GLMath Header

struct VertexFormat
{
	glm::vec3 position;	//position of the vertex

	VertexFormat(const glm::vec3 p)	//constructor, with read only input
	{
		position = p;
	}
};

#endif
