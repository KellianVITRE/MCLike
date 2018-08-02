#pragma once
#include "Includes.h"
class Camera
{
public:
	Camera(glm::vec3 position, glm::vec3 rotation, GLfloat FOV, GLfloat aspect, GLfloat renderDistance);
	~Camera();

	void setAspect(GLfloat aspect);

	void update();

	void processInput(GLFWwindow* window);

	void mouseInput(float x, float y, float width, float height);

	glm::mat4 getProjectionView();

	glm::vec3 getPosition() { return m_position; };

private:
	glm::vec3 m_position;
	glm::vec3 m_front;
	glm::vec3 m_up;

	glm::vec3 m_rotation;

	GLfloat m_aspect;
	GLfloat m_FOV;
	GLfloat m_renderDistance;
};

