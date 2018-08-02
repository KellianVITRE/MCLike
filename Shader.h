#pragma once

#include "Includes.h"

enum {
	CAMERA_UNIFORM,
	NUM_UNIFORMS
};

class ShaderProgram {
public:
	ShaderProgram(const char* vertexFile, const char* fragmentFile);
	~ShaderProgram();

	void Bind();
	void Unbind();

	void SetUniformMat4(glm::mat4 matrix);
private:
	GLuint m_program;
	GLuint m_vertexShader;
	GLuint m_fragmentShader;

	GLuint m_uniforms[NUM_UNIFORMS];
};