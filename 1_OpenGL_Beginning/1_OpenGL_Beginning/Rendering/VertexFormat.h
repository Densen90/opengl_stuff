#pragma once
#include "glm\glm.hpp"	//GLMath Header

namespace Rendering
{
	struct VertexFormat
	{
		glm::vec3 position;	//position of the vertex
		glm::vec4 color;

		VertexFormat() {}

		VertexFormat(const glm::vec3 &pos, const glm::vec4 &col)	//constructor, with read only input
		{
			position = pos;
			color = col;
		}
	};
}
