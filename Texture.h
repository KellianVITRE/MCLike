#pragma once

#include "Includes.h"

class Texture
{
public:
	Texture(const std::string fileName);

	void Bind();

	virtual ~Texture();
protected:
private:
	Texture(const Texture& texture) {}
	void operator=(const Texture& texture) {}

	int width, height, numComponents;

	unsigned char* datas;

	GLuint m_texture;
};