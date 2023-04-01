#include "TriangleSurface.h"
#include "FileManager.h"

TriangleSurface::TriangleSurface()
{
    mMatrix = glm::mat4(1.0f);
}

TriangleSurface::TriangleSurface(std::string filename, bool ReadFileCheck)
{
	if (ReadFileCheck)
	{
		FileManager* f = new FileManager();
		f->ReadFile(filename, mVertices);
	}
}

void TriangleSurface::init(GLint matrixUniform)
{
    mMatrixUniform = matrixUniform;

    glGenVertexArrays(1, &mVAO);
    glBindVertexArray(mVAO);

    //Vertex Buffer Object to hold vertices - VBO
    glGenBuffers(1, &mVBO);
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);

    //Vertex Buffer Object to hold vertices - VBO
    glBufferData(GL_ARRAY_BUFFER, mVertices.size() * sizeof(Vertex), mVertices.data(), GL_DYNAMIC_DRAW);

    // 1rst attribute buffer : vertices
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);          // array buffer offset
    glEnableVertexAttribArray(0);

    // 2nd attribute buffer : colors
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    // 3rd attribute buffer : uvs
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

    glBindVertexArray(0);

}

void TriangleSurface::draw(Shader shader)
{

    glBindVertexArray(mVAO);
    //glUniformMatrix4fv(mMatrixUniform, 1, GL_FALSE, shader);
    shader.setMat4("model", mMatrix);
    glDrawArrays(GL_TRIANGLES, 0, mVertices.size());

}

