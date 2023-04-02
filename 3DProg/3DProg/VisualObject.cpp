#include "VisualObject.h"

VisualObject::VisualObject()
{
	mMatrix = glm::mat4(1.0f);
}

VisualObject::~VisualObject()
{
	glDeleteVertexArrays(1, &mVAO);
	glDeleteBuffers(1, &mVBO);
}