#pragma once
#include "Model.h"
#include "CubeMesh.h"
class ChunkModel :
	public Model
{
public:
	ChunkModel(glm::vec4 position);
	~ChunkModel();
private:
	glm::vec3 m_position;
	std::vector<CubeMesh> cubes;
};

