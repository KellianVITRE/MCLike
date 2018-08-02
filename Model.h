#pragma once
#include "Mesh.h"

enum
{
	POSITION_VB,
	COLOR_VB,
	NORMAL_VB,
	INDEX_VB,
	NUM_BUFFERS
};

class Model
{
public:
	Model();
	~Model();

	void InitModel(Mesh mesh);
	void InitModel(std::vector<Mesh> meshes);

	void Draw();

protected:
	GLuint m_vbo[NUM_BUFFERS];
	GLuint m_vao;

	int indexNumber;
	int vertexNumber;
};

