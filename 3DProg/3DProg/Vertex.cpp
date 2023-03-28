#include "Vertex.h"

Vertex::Vertex()
{
	xyz[0] = 0.0f;
	xyz[1] = 0.0f;
	xyz[2] = 0.0f;
	rgb[0] = 0.0f;
	rgb[0] = 0.0f;
	rgb[0] = 0.0f;
	uv[0] = 0.0f;
	uv[1] = 0.0f;
}

Vertex::Vertex(float x, float y, float z, float r, float g, float b, float u, float v)
{
	xyz[0] = x;
	xyz[1] = y;
	xyz[2] = z;
	rgb[0] = r;
	rgb[0] = g;
	rgb[0] = b;
	uv[0] = u;
	uv[1] = v;
}
