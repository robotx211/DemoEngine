#include <memory>
#include <glm/glm.hpp>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>

#include <myengine/myengine.h>

#include "CameraController.h"
#include "GameController.h"

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

	m_ray = myEngine::Ray(getCore(), getTransform()->getLocalPosition(), getTransform()->getForward());
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

	getTransform()->worldAxisRotateEulerDegrees(0.0f, yaw, 0.0f);
	getTransform()->localAxisRotateEulerDegrees(pitch, 0.0f, 0.0f); //removing this makes it look left and right only

	float forwardMovement = 0.0f;
	float strafeMovement = 0.0f;

	if (getCore()->getKeyboard()->getKey(SDL_SCANCODE_W))
	{
		forwardMovement += 1.0f;
	}
	else if (getCore()->getKeyboard()->getKey(SDL_SCANCODE_S))
	{
		forwardMovement -= 1.0f;
	}

	if (getCore()->getKeyboard()->getKey(SDL_SCANCODE_A))
	{
		strafeMovement += 1.0f;
	}
	else if (getCore()->getKeyboard()->getKey(SDL_SCANCODE_D))
	{
		strafeMovement -= 1.0f;
	}

	glm::vec3 moveVec = (  glm::normalize(getTransform()->getForward()) * forwardMovement * m_movementSpeed) + ( glm::normalize(getTransform()->getLeft()) * strafeMovement * m_movementSpeed);

	getTransform()->translate(moveVec);

	//if (getCore()->getKeyboard()->getKey(SDL_SCANCODE_SPACE))
	//{
	//	m_ray.setOrigin(getTransform()->getLocalPosition());
	//	m_ray.setDirection(getTransform()->getForward());
	//
	//	if (m_ray.rayCast() == true)
	//	{
	//		std::vector < std::shared_ptr<myEngine::Collider>> collisions = m_ray.getCollisions();

	//		for (size_t i = 0; i < collisions.size(); i++)
	//		{
	//			if (collisions.at(i)->getEntity()->getName() == "enemy")
	//			{
	//				collisions.at(i)->getEntity()->markForDeletion();
	//				m_enemiesKilled++;
	//			}
	//		}
	//	}
	//}

}
void CameraController::lateUpdate()
{
	//std::shared_ptr<myEngine::RigidBody> rb = getEntity()->getComponent <myEngine::RigidBody>();

	//if (rb == NULL)
	//{
	//	return;
	//}

	//if (rb->isColliding() == true)
	//{
	//	for (size_t i = 0; i < rb->getCollisions().size(); i++)
	//	{
	//		if (rb->getCollisions().at(i)->getEntity()->getName() == "enemy")
	//		{
	//			//m_gameController.lock()->reset();
	//		}
	//	}
	//}
}




void CameraController::setPitchLimits(float _min, float _max)
{


	m_pitchMin = _min;
	m_pitchMax = _max;
}