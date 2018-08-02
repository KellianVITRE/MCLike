#include "Application.h"

Application::Application(int width, int height, double tickRateLimit) {
	initGLFW();
	m_context = new Context(width, height, "Minecraft-Like");
	m_context->use();
	initGLEW();

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glDepthMask(GL_FALSE);

	this->tickRateLimit = tickRateLimit;

	ticks = 0;
	frames = 0;

	m_shaders = new ShaderProgram("Shaders/basicShader.vs", "Shaders/basicShader.fs");
	m_camera = new Camera(glm::vec3(0.0, 0.0, 0.1), glm::vec3(90.0, 0.0, 0.0), 45.0f,
		(float)m_context->getWidth()/(float)m_context->getHeight(), 1000.0f);
	m_texture = new Texture("assets/textures.png");
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			m_chunks.push_back(new ChunkModel(glm::vec4(i*16, 0.0f, j*16, 1.0f)));
		}
	}

	isTracking = true;
}

Application::~Application() {
	delete m_context;
}

void Application::run()
{
	glfwSwapInterval(0);

	double lastUpdateTime = 0.0f;
	double lastFPSShow = 2.0f;

	while (m_context->open()) {

		double now = glfwGetTime();

		double dt = now - lastUpdateTime;
		double dt2 = now - lastFPSShow;
		if (dt2 > 1.0) {
			std::cout << "TPS:" << (int)round(ticks / now) << " | FPS: " << (int)round(frames / now) << std::endl;
			lastFPSShow += dt2;
			dt2--;
		}
		
		if (dt > 1.0 / tickRateLimit) {
			ticks++;
			update(now);

			dt--;
			lastUpdateTime = now;
		}
		

		frames++;
		render(now);
	}
}

void Application::update(double nt) {

	if (isTracking) {
		m_camera->mouseInput(m_context->getMouseX(), m_context->getMouseY(), m_context->getWidth(), m_context->getHeight());
		m_camera->processInput(m_context->getWindow());
	}
	m_camera->update();

	m_context->pollEvents();
	if (isTracking) {
		m_context->setMousePosition(m_context->getWidth() / 2, m_context->getHeight() / 2);
	}
	if (glfwGetKey(m_context->getWindow(), GLFW_KEY_ESCAPE)) {
		glfwTerminate();
		m_context->close();
	}
	if (glfwGetKey(m_context->getWindow(), GLFW_KEY_N)) {
		if (isTracking) {
			isTracking = false;
		}
		else {
			isTracking = true;
		}
	}
}

void Application::render(double nt) {
	m_context->clear();
	
	m_shaders->SetUniformMat4(m_camera->getProjectionView()*glm::mat4(1.0f));

	m_texture->Bind();
	m_shaders->Bind();
	
	for (int i = 0; i < 4; i++) {
		m_chunks[i]->Draw();
	}

	m_context->swapBuffers();
}

void Application::initGLFW() {
	if (!glfwInit()) {
		std::cerr << "Couldn't initialize GLFW." << std::endl;
		system("PAUSE");
		exit(EXIT_FAILURE);
	}
}

void Application::initGLEW() {

	glewExperimental = GL_TRUE;

	GLenum err = glewInit();
	if (err != GLEW_OK) {
		std::cerr << "Couldn't initialize GLEW: " << glewGetErrorString(err) << std::endl;
		glfwTerminate();
		system("PAUSE");
		exit(EXIT_FAILURE);
	}
}