#pragma once

#include "Includes.h"

class Context
{
public:
	Context(int width, int height, const char* title);
	~Context();

	void use();

	void clear();

	void swapBuffers();

	void pollEvents();

	// Getters

	inline bool open() { return m_open; }
	inline void close() { m_open = false;  }

	int getWidth();
	int getHeight();

	double getMouseX();
	double getMouseY();

	void setMousePosition(double x, double y);

	inline GLFWwindow* getWindow() { return m_window; }

private:
	GLFWwindow * m_window = 0;
	bool m_open;
};