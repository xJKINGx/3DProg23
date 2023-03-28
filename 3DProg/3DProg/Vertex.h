#ifndef VERTEX_CLASS_H
#define VERTEX_CLASS_H

#include <glm/glm.hpp>

class Vertex
{
public:
	glm::vec3 xyz;
	glm::vec3 rgb;
	glm::vec2 uv;

	Vertex();
	Vertex(float x, float y, float z, float r, float g, float b, float u, float v);
};

#endif