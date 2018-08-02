#include "Model.h"

Model::Model()
{
	glGenVertexArrays(1, &m_vao);
	glGenBuffers(NUM_BUFFERS, m_vbo);
}

Model::~Model()
{
	glDeleteVertexArrays(1, &m_vao);
	glDeleteBuffers(1, m_vbo);
}

void Model::InitModel(Mesh mesh)
{
	this->indexNumber = mesh.indexNumber;
	this->vertexNumber = mesh.vertexNumber;

	glm::vec4* pos = new glm::vec4[mesh.vertexNumber];
	glm::vec2* tcoords = new glm::vec2[mesh.vertexNumber];
	glm::vec4* normals = new glm::vec4[mesh.vertexNumber];

	for (int i = 0; i < mesh.vertexNumber; i++) {
		pos[i] = mesh.vertices[i].position;
		tcoords[i] = mesh.vertices[i].tcoords;
		normals[i] = mesh.vertices[i].normal;
	}

	glBindVertexArray(m_vao);

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo[POSITION_VB]);

	glBufferData(GL_ARRAY_BUFFER, sizeof(mesh.vertices[0].position)*mesh.vertexNumber, &pos[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo[COLOR_VB]);

	glBufferData(GL_ARRAY_BUFFER, sizeof(mesh.vertices[0].tcoords)*mesh.vertexNumber, &tcoords[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo[NORMAL_VB]);

	glBufferData(GL_ARRAY_BUFFER, sizeof(mesh.vertices[0].normal)*mesh.vertexNumber, &normals[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vbo[INDEX_VB]);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(mesh.indices[0])*mesh.indexNumber, &mesh.indices[0], GL_STATIC_DRAW);
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glBindVertexArray(0);
}

void Model::InitModel(std::vector<Mesh> meshes)
{
	Mesh mesh;

	for (int i = 0; i < meshes.size(); i++) {
		mesh.combinate(meshes[i]);
	}

	for (int i = 0; i < mesh.indexNumber; i++) {
		std::cout << "i: " << mesh.indices[i] << std::endl << std::endl;
	}

	this->indexNumber = mesh.indexNumber;
	this->vertexNumber = mesh.vertexNumber;

	glm::vec4* pos = new glm::vec4[mesh.vertexNumber];
	glm::vec2* tcoords = new glm::vec2[mesh.vertexNumber];
	glm::vec4* normals = new glm::vec4[mesh.vertexNumber];

	for (int i = 0; i < mesh.vertexNumber; i++) {
		pos[i] = mesh.vertices[i].position;
		tcoords[i] = mesh.vertices[i].tcoords;
		normals[i] = mesh.vertices[i].normal;
	}

	glBindVertexArray(m_vao);

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo[POSITION_VB]);

	glBufferData(GL_ARRAY_BUFFER, sizeof(mesh.vertices[0].position)*mesh.vertexNumber, &pos[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo[COLOR_VB]);

	glBufferData(GL_ARRAY_BUFFER, sizeof(mesh.vertices[0].tcoords)*mesh.vertexNumber, &tcoords[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo[NORMAL_VB]);

	glBufferData(GL_ARRAY_BUFFER, sizeof(mesh.vertices[0].normal)*mesh.vertexNumber, &normals[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vbo[INDEX_VB]);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(mesh.indices[0])*mesh.indexNumber, &mesh.indices[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

}

void Model::Draw()
{
	glBindVertexArray(m_vao);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vbo[INDEX_VB]);

	glDrawElements(GL_TRIANGLES, indexNumber, GL_UNSIGNED_INT, 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glBindVertexArray(0);
}
