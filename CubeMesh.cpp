#include "CubeMesh.h"

CubeMesh::CubeMesh(glm::vec4 position, int id)
{
		float offsetY = (float)id / (float)CubeData::ID_NUMBER;

		vertices.push_back(Vertex(glm::vec4(-1.0, -1.0, 1.0, 1.0) + position, glm::vec2(0.0f, CubeData::TOP_Y(id)), glm::vec4(0, 0, 1, 1)));
		vertices.push_back(Vertex(glm::vec4(1.0, -1.0, 1.0, 1.0) + position, glm::vec2(1.0f/6, CubeData::TOP_Y(id)), glm::vec4(1, 0, 1, 1)));
		vertices.push_back(Vertex(glm::vec4(1.0, 1.0, 1.0, 1.0) + position, glm::vec2(1.0f /6, CubeData::BOTTOM_Y(id)), glm::vec4(1, 1, 1, 1)));
		vertices.push_back(Vertex(glm::vec4(-1.0, 1.0, 1.0, 1.0) + position, glm::vec2(0.0f, CubeData::BOTTOM_Y(id)), glm::vec4(0, 1, 1, 1)));

		vertices.push_back(Vertex(glm::vec4(1.0, 1.0, 1.0, 1.0) + position, glm::vec2(1.0f / 6, CubeData::BOTTOM_Y(id)), glm::vec4(1, 1, 1, 1)));
		vertices.push_back(Vertex(glm::vec4(1.0, 1.0, -1.0, 1.0) + position, glm::vec2(2.0f / 6, CubeData::BOTTOM_Y(id)), glm::vec4(1, 1, 0, 1)));
		vertices.push_back(Vertex(glm::vec4(1.0, -1.0, -1.0, 1.0) + position, glm::vec2(2.0f / 6, CubeData::TOP_Y(id)), glm::vec4(1, 0, 0, 1)));
		vertices.push_back(Vertex(glm::vec4(1.0, -1.0, 1.0, 1.0) + position, glm::vec2(1.0f / 6, CubeData::TOP_Y(id)), glm::vec4(1, 0, 1, 1)));

		vertices.push_back(Vertex(glm::vec4(-1.0, -1.0, -1.0, 1.0) + position, glm::vec2(2.0f / 6, CubeData::TOP_Y(id)), glm::vec4(0, 0, 0, 1)));
		vertices.push_back(Vertex(glm::vec4(1.0, -1.0, -1.0, 1.0) + position, glm::vec2(3.0f / 6, CubeData::TOP_Y(id)), glm::vec4(1, 0, 0, 1)));
		vertices.push_back(Vertex(glm::vec4(1.0, 1.0, -1.0, 1.0) + position, glm::vec2(3.0f / 6, CubeData::BOTTOM_Y(id)), glm::vec4(1, 1, 0, 1)));
		vertices.push_back(Vertex(glm::vec4(-1.0, 1.0, -1.0, 1.0) + position, glm::vec2(2.0f / 6, CubeData::BOTTOM_Y(id)), glm::vec4(0, 1, 0, 1)));

		vertices.push_back(Vertex(glm::vec4(-1.0, -1.0, -1.0, 1.0) + position, glm::vec2(3.0f / 6, CubeData::TOP_Y(id)), glm::vec4(0, 0, 0, 1)));
		vertices.push_back(Vertex(glm::vec4(-1.0, -1.0, 1.0, 1.0) + position, glm::vec2(4.0f / 6.0f, CubeData::TOP_Y(id)), glm::vec4(0, 0, 1, 1)));
		vertices.push_back(Vertex(glm::vec4(-1.0, 1.0, 1.0, 1.0) + position, glm::vec2(4.0f / 6.0f, CubeData::BOTTOM_Y(id)), glm::vec4(0, 1, 1, 1)));
		vertices.push_back(Vertex(glm::vec4(-1.0, 1.0, -1.0, 1.0) + position, glm::vec2(3.0f / 6, CubeData::BOTTOM_Y(id)), glm::vec4(0, 1, 0, 1)));

		vertices.push_back(Vertex(glm::vec4(1.0, 1.0, 1.0, 1.0) + position, glm::vec2(4.0f / 6.0f, CubeData::TOP_Y(id)), glm::vec4(1, 1, 1, 1)));
		vertices.push_back(Vertex(glm::vec4(-1.0, 1.0, 1.0, 1.0) + position, glm::vec2(4.0f / 6.0f, CubeData::TOP_Y(id)), glm::vec4(0, 1, 1, 1)));
		vertices.push_back(Vertex(glm::vec4(-1.0, 1.0, -1.0, 1.0) + position, glm::vec2(4.0f / 6.0f, CubeData::BOTTOM_Y(id)), glm::vec4(0, 1, 0, 1)));
		vertices.push_back(Vertex(glm::vec4(1.0, 1.0, -1.0, 1.0) + position, glm::vec2(4.0f / 6.0f, CubeData::BOTTOM_Y(id)), glm::vec4(1, 1, 0, 1)));

		vertices.push_back(Vertex(glm::vec4(-1.0, -1.0, -1.0, 1.0) + position, glm::vec2(5.0f / 6.0f, CubeData::BOTTOM_Y(id)), glm::vec4(0, 0, 0, 1)));
		vertices.push_back(Vertex(glm::vec4(1.0, -1.0, -1.0, 1.0) + position, glm::vec2(1.0, CubeData::BOTTOM_Y(id)), glm::vec4(1, 0, 0, 1)));
		vertices.push_back(Vertex(glm::vec4(1.0, -1.0, 1.0, 1.0) + position, glm::vec2(1.0, CubeData::TOP_Y(id)), glm::vec4(1, 0, 1, 1)));
		vertices.push_back(Vertex(glm::vec4(-1.0, -1.0, 1.0, 1.0) + position, glm::vec2(5.0f / 6.0f, CubeData::TOP_Y(id)), glm::vec4(0, 0, 1, 1)));

		indices = {
			0,  1,  2,  0,  2,  3,   //front
			4,  5,  6,  4,  6,  7,   //right
			8,  9,  10, 8,  10, 11,  //back
			12, 13, 14, 12, 14, 15,  //left
			16, 17, 18, 16, 18, 19,  //upper
			20, 21, 22, 20, 22, 23 };

		vertexNumber = vertices.size();
		indexNumber = indices.size();
}


CubeMesh::~CubeMesh()
{
}

float CubeData::BOTTOM_Y(int id)
{
	return (float)id / (float)ID_NUMBER;
}

float CubeData::TOP_Y(int id)
{
	return (float)(id+1) / (float)ID_NUMBER;
}
