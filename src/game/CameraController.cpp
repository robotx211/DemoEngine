#include <myengine/myengine.h>

#include "CameraController.h"

CameraController::CameraController()
{

	m_speed = 1.0f;

	m_pitch = 0.0f;
	m_yaw = 0.0f;

	m_pitchMin = -90.0f;
	m_pitchMax = 90.0f;

}
CameraController::~CameraController()
{

}

void CameraController::start()
{
	//getCore()->getMouse()->setCentreLocked(true);
}

void CameraController::update()
{
	float yaw = 0; //about y, degrees
	float pitch = 0; //about x, degrees

	if (getCore()->getKeyboard()->getKey(SDL_SCANCODE_W))
	{
		pitch -= 1.0f;
	}
	else if (getCore()->getKeyboard()->getKey(SDL_SCANCODE_S))
	{
		pitch += 1.0f;
	}

	if (getCore()->getKeyboard()->getKey(SDL_SCANCODE_A))
	{
		yaw += 1.0f;
	}
	else if (getCore()->getKeyboard()->getKey(SDL_SCANCODE_D))
	{
		yaw -= 1.0f;
	}

	if (m_pitch + pitch > m_pitchMax)
	{
		pitch = m_pitchMax - m_pitch;
	}
	else if (m_pitch - pitch < m_pitchMin)
	{
		pitch = m_pitchMin + m_pitch;
	}

	m_pitch += pitch;
	m_yaw += yaw;

	m_yaw = glm::mod(m_yaw, 360.0f);

	if (getCore()->getKeyboard()->getKey(SDL_SCANCODE_SPACE))
	{
		getTransform()->setLocalOrientation(glm::quat(glm::vec3(0.0f, 0.0f, 0.0f)));
	}

	glm::quat qYaw = glm::quat(glm::vec3(0.0f, glm::radians(yaw), 0.0f));
	glm::quat qPitch = glm::quat(glm::vec3(glm::radians(pitch), 0.0f, 0.0f));

	glm::quat currOrientation = getTransform()->getLocalOrientation();

	getTransform()->setLocalOrientation(qPitch * currOrientation * qYaw);

	std::cout << "tYaw: " << m_yaw << ", tPitch: " << m_pitch << std::endl;

}



void CameraController::setPitchLimits(float _min, float _max)
{
}