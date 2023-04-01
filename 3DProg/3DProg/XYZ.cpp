#include "XYZ.h"

XYZ::XYZ()
{
	float size = 10.f;
	mVertices.push_back(Vertex(-size, 0, 0,		1, 0, 0,	0, 0));
	mVertices.push_back(Vertex(size, 0, 0,		1, 0, 0,	0, 0));
	mVertices.push_back(Vertex(0, -size, 0,		0, 1, 0,	0, 0));
	mVertices.push_back(Vertex(0, size, 0,		0, 1, 0,	0, 0));
	mVertices.push_back(Vertex(0, 0, -size,		0, 0, 1,	0, 0));
	mVertices.push_back(Vertex(0, 0, size,		0, 0, 1,	0, 0));
}

XYZ::~XYZ()
{

}

void XYZ::init(/*GLint matrixUniform*/)
{
	// Generate the VAO and VBO with only 1 object each
	glGenVertexArrays(1, &mVAO);
	glGenBuffers(1, &mVBO);

	// Make the VAO the current Vertex Array Object by binding it
	glBindVertexArray(mVAO);

	// Bind the VBO specifying it's a GL_ARRAY_BUFFER
	glBindBuffer(GL_ARRAY_BUFFER, mVBO);
	// Introduce the vertices into the VBO
	glBufferData(GL_ARRAY_BUFFER, mVertices.size() * sizeof(Vertex), mVertices.data(), GL_STATIC_DRAW);


	// Configure the Vertex Attribute so that OpenGL knows how to read the VBO
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
	// Enable the Vertex Attribute so that OpenGL knows to use it
	glEnableVertexAttribArray(0);

	// Configure the Vertex Attribute so that OpenGL knows how to read the VBO
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
	// Enable the Vertex Attribute so that OpenGL knows to use it
	glEnableVertexAttribArray(1);

	// Configure the Vertex Attribute so that OpenGL knows how to read the VBO
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
	// Enable the Vertex Attribute so that OpenGL knows to use it
	glEnableVertexAttribArray(2);


	// Bind both the VBO and VAO to 0 so that we don't accidentally modify the VAO and VBO we created
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void XYZ::draw()
{
	glBindVertexArray(mVAO);
	glDrawArrays(GL_LINES, 0, mVertices.size());
}
