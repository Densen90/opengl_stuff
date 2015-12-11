#pragma once
#include "VertexFormat.h"
#include "../Dependencies/glew/glew.h"
#include "../Dependencies/freeglut/freeglut.h"
#include <vector>
#include <iostream>

namespace Rendering
{
	class IGameObject
	{
	public:
		virtual ~IGameObject();

		virtual void Draw() = 0;
		virtual void Update() = 0;
		virtual void SetProgram(GLuint shaderName) = 0;
		virtual void Destroy() = 0;

		virtual GLuint GetVao() const = 0;
		virtual const std::vector<GLuint> &GetVbos() const = 0;
	};

	inline IGameObject::~IGameObject() {}
}
