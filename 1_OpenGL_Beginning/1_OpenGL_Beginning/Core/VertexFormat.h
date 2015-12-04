#pragma once

#include "glm\glm.hpp"	//GLMath Header

struct VertexFormat
{
	glm::vec3 position;	//position of the vertex
	glm::vec4 color;

	VertexFormat(const glm::vec3 p, const glm::vec4 c)	//constructor, with read only input
	{
		position = p;
		color = c;
	}
};
