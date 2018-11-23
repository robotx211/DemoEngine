#include <myengine/myengine.h>

#include "CameraController.h"

CameraController::CameraController()
{

	m_cameraSpeed = 0.0f;
	m_movementSpeed = 0.0f;

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

	if (getCore()->getKeyboard()->getKey(SDL_SCANCODE_UP))
	{
		pitch += 1.0f;
	}
	else if (getCore()->getKeyboard()->getKey(SDL_SCANCODE_DOWN))
	{
		pitch -= 1.0f;
	}

	if (getCore()->getKeyboard()->getKey(SDL_SCANCODE_LEFT))
	{
		yaw -= 1.0f;
	}
	else if (getCore()->getKeyboard()->getKey(SDL_SCANCODE_RIGHT))
	{
		yaw += 1.0f;
	}

	if (m_pitch + pitch > m_pitchMax)
	{
		pitch = m_pitchMax - m_pitch;
	}
	else if (m_pitch + pitch < m_pitchMin)
	{
		pitch = m_pitchMin - m_pitch;
	}

	m_pitch += pitch;
	m_yaw += yaw;

	m_yaw = glm::mod(m_yaw, 360.0f);

	std::cout << "Total Pitch: " << m_pitch << "\tMaxPitch: " << m_pitchMax << "\tPitch Change: " << pitch << std::endl;

	getTransform()->worldAxisRotateEulerDegrees(0.0f, yaw, 0.0f);
	getTransform()->localAxisRotateEulerDegrees(pitch, 0.0f, 0.0f);

	//std::cout << "tYaw: " << m_yaw << ", tPitch: " << m_pitch << std::endl;



	float movement = 0.0f;

	if (getCore()->getKeyboard()->getKey(SDL_SCANCODE_W))
	{
		movement += 1.0f;
	}
	else if (getCore()->getKeyboard()->getKey(SDL_SCANCODE_S))
	{
		movement -= 1.0f;
	}

	glm::vec3 moveVec = getTransform()->getForward() * movement * m_movementSpeed;

	getTransform()->translate(moveVec * glm::vec3(1, 0, 1));

	if (getCore()->getKeyboard()->getKey(SDL_SCANCODE_SPACE))
	{
		//m_sound->play();
	}

}



void CameraController::setPitchLimits(float _min, float _max)
{
}