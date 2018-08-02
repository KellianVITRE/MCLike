#pragma once

#include "Includes.h"

#include "Context.h"
#include "Shader.h"
#include "Camera.h"
#include "ChunkModel.h"
#include "Texture.h"
class Application {
public:
	Application(int width, int height, double tickRateLimit);
	~Application();

	void run();
	void update(double nt);
	void render(double nt);
private:
	void initGLFW();
	void initGLEW();

	Context * m_context = 0;
	ShaderProgram * m_shaders = 0;
	Camera * m_camera = 0;
	Texture * m_texture = 0;
	std::vector<ChunkModel*> m_chunks;

	double tickRateLimit;

	int ticks;
	int frames;

	bool isTracking;
};