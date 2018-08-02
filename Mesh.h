#pragma once

#include "Includes.h"

struct Vertex {
	Vertex(glm::vec4 position, glm::vec2 tcoords, glm::vec4 normal);
	Vertex() = default;
	glm::vec4 position;
	glm::vec2 tcoords;
	glm::vec4 normal;
};

struct Mesh {
	Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices);
	Mesh();
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;

	void combinate(Mesh m);

	int indexNumber;
	int vertexNumber;;
};