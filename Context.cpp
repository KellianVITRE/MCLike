#include "Context.h"

Context::Context(int width, int height, const char* title) {
	m_window = glfwCreateWindow(width, height, title, NULL, NULL);

	if (!m_window) {
		std::cerr << "Couldn't create the window" << std::endl;
		exit(EXIT_FAILURE);
	}
}

Context::~Context() {
	glfwDestroyWindow(m_window);
	glfwTerminate();
}

void Context::use() {
	glfwMakeContextCurrent(m_window);

	m_open = true;
}

void Context::clear() {
	glClearColor(0.9f, 0.9f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Context::swapBuffers() {
	glfwSwapBuffers(m_window);
}

void Context::pollEvents() {
	glfwPollEvents();
	if (glfwWindowShouldClose(m_window)) {
		m_open = false;
	}
}

int Context::getWidth() {
	int width;
	int height;

	glfwGetWindowSize(m_window, &width, &height);

	return width;
}

int Context::getHeight() {
	int width;
	int height;

	glfwGetWindowSize(m_window, &width, &height);

	return height;
}

double Context::getMouseX()
{
	double x, y;

	glfwGetCursorPos(m_window, &x, &y);

	return x;
}

double Context::getMouseY()
{
	double x, y;

	glfwGetCursorPos(m_window, &x, &y);

	return y;
}

void Context::setMousePosition(double x, double y)
{
	glfwSetCursorPos(m_window, x, y);
}
