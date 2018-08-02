#include "Mesh.h"

Vertex::Vertex(glm::vec4 position, glm::vec2 tcoords, glm::vec4 normal)
{
	this->position = position;
	this->tcoords = tcoords;
	this->normal = normal;
}

Mesh::Mesh()
{
	this->vertexNumber = 0;
	this->indexNumber = 0;
}

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices)
{
	this->vertices = vertices;
	this->indices = indices;
	this->vertexNumber = vertices.size();
	this->indexNumber = indices.size();
}

void Mesh::combinate(Mesh m)
{
	for (int i = 0; i < m.vertexNumber; i++) {
		this->vertices.push_back(m.vertices[i]);
	}

	for (int i = 0; i < m.indexNumber; i++) {
		this->indices.push_back(m.indices[i]+indexNumber);
	}

	this->vertexNumber = vertices.size();
	this->indexNumber = indices.size();
}
