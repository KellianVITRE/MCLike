#pragma once
#include "Mesh.h"

namespace CubeData {

	enum ID {
		GRASS,
		STONE,
		DIRT,
		AIR,
		BEDROCK,
		ID_NUMBER
	};

	float BOTTOM_Y(int id);
	float TOP_Y(int id);
}

struct CubeMesh
	: public Mesh
{
	CubeMesh(glm::vec4 position, int id);
	~CubeMesh();
};

