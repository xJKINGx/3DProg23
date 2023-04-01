#ifndef VISUALOBJECT_CLASS_H
#define VISUALOBJECT_CLASS_H

#include <glad/glad.h>
#include <glm/gtc/matrix_transform.hpp>
#include "ShaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"

#include "Vertex.h"
#include <vector>

class VisualObject
{
public:

	VisualObject();
	~VisualObject();

	virtual void init(GLint matrixUniform) = 0;
	virtual void draw() = 0;

protected:
	std::vector<Vertex> mVertices;

	GLuint mVAO{ 0 };
	GLuint mVBO{ 0 };
	GLint mMatrixUniform{ 0 };

	glm::mat4 mMatrix; // Model Matrix
};

#endif