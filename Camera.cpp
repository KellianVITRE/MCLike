#include "Camera.h"



Camera::Camera(glm::vec3 position, glm::vec3 rotation, GLfloat FOV, GLfloat aspect, GLfloat renderDistance)
	: m_position(position), m_rotation(rotation), m_FOV(FOV), m_aspect(aspect), m_renderDistance(renderDistance)
{
	
	m_front.x = cos(glm::radians(m_rotation.x)) * cos(glm::radians(m_rotation.y));
	m_front.y = sin(glm::radians(m_rotation.y));
	m_front.z = sin(glm::radians(m_rotation.x)) * cos(glm::radians(m_rotation.y));

	m_up = glm::vec3(0, 1, 0);
}


Camera::~Camera()
{
}

void Camera::setAspect(GLfloat aspect)
{
	m_aspect = aspect;
}

void Camera::update()
{
	m_front.x = cos(glm::radians(m_rotation.x)) * cos(glm::radians(m_rotation.y));
	m_front.y = sin(glm::radians(m_rotation.y));
	m_front.z = sin(glm::radians(m_rotation.x)) * cos(glm::radians(m_rotation.y));
}

void Camera::processInput(GLFWwindow* window)
{
	glm::vec3 front = m_front;
	front.y = 0.0f;

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS ) {
		m_position += front * 0.1f;
	}
	else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		m_position -= front * 0.1f;
	}
	else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		m_position += glm::normalize(glm::cross(front, m_up)) * 0.1f;
	}
	else if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		m_position -= glm::normalize(glm::cross(front, m_up)) * 0.1f;
	}
	else if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
		m_position += m_up * 0.1f;
	}
	else if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
		m_position -= m_up * 0.1f;
	}
}

void Camera::mouseInput(float x, float y, float width, float height)
{
	float dx = width/2 - x;
	float dy = height/2 - y;

	m_rotation.x -= dx;
	m_rotation.y += dy;

	if (m_rotation.y > 89.9f) {
		m_rotation.y = 89.9f;
	}
	if (m_rotation.y < -89.9f) {
		m_rotation.y = -89.9f;
	}
}

glm::mat4 Camera::getProjectionView()
{
	glm::mat4 projection = glm::perspective(m_FOV, m_aspect, 0.01f, m_renderDistance);
	glm::mat4 view = glm::lookAt(m_position, m_position + m_front, glm::vec3(0, 1, 0));

	glm::mat4 VP = projection * view;

	return VP;
}

