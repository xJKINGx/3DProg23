#ifndef VISUALOBJECT_CLASS_H
#define VISUALOBJECT_CLASS_H

#include <glad/glad.h>
#include "Vertex.h"
#include <vector>

class VisualObject
{
public:
	VisualObject();
	~VisualObject();
protected:
	std::vector<Vertex*> mVertices;

	GLuint mVAO{ 0 };
	GLuint mVBO{ 0 };
	GLint mMatrixUniform{ 0 };
};

#endif