#include "ChunkModel.h"



ChunkModel::ChunkModel(glm::vec4 position)
{
	int id;

	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			for (int k = 0; k < 16; k++) {
				if (j > 12) {
					if (j == 15) {
						id = CubeData::ID::GRASS;
					}
					else {
						id = CubeData::ID::DIRT;
					}
				}
				else {
					id = CubeData::ID::STONE;
				}
				cubes.push_back(CubeMesh(glm::vec4(i, j, k, 1.0) + position, id));
			}
		}
	}

	Mesh mesh;

	for (int i = 0; i < cubes.size(); i++) {
		mesh.combinate(cubes[i]);
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


ChunkModel::~ChunkModel()
{
}
