#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>
#include <glm/glm.hpp>

std::string GetFileContents(const char* filename);

class Shader
{
public:
	GLuint ID;
	Shader(const char* vertexFile, const char* fragmentFile);

	void Activate();
	void Delete();

    // utility uniform functions
    // ------------------------------------------------------------------------
    void setBool(const std::string& name, bool value) const;

    // ------------------------------------------------------------------------
    void setInt(const std::string& name, int value) const;

    // ------------------------------------------------------------------------
    void setFloat(const std::string& name, float value) const;

    // ------------------------------------------------------------------------
    void setVec2(const std::string& name, const glm::vec2& value) const;

    void setVec2(const std::string& name, float x, float y) const;

    // ------------------------------------------------------------------------
    void setVec3(const std::string& name, const glm::vec3& value) const;

    void setVec3(const std::string& name, float x, float y, float z) const;

    // ------------------------------------------------------------------------
    void setVec4(const std::string& name, const glm::vec4& value) const;

    void setVec4(const std::string& name, float x, float y, float z, float w) const;

    //
    // NAME HERE MEANS THE NAME IN THE .FRAG AND .VERT SHADER FILES
    // MAT MEANS THE MATRIX WE NEED TO PASS THROUGH
    // For example if we want to move something and give it to the shader, we use the name "model"
    // and the mat will be mMatrix, aka. Model Matrix.
    // The differentl functions are for differenty sizes, for exmaple setMat2 is for 2x2 matrices.
    //

    // ------------------------------------------------------------------------
    void setMat2(const std::string& name, const glm::mat2& mat) const;

    // ------------------------------------------------------------------------
    void setMat3(const std::string& name, const glm::mat3& mat) const;

    // ------------------------------------------------------------------------
    void setMat4(const std::string& name, const glm::mat4& mat) const;

};


#endif