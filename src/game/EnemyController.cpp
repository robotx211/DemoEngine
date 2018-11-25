#include "EnemyController.h"
#include "CameraController.h"

EnemyController::EnemyController()
{

}
EnemyController::~EnemyController()
{

}

void EnemyController::start()
{

}
void EnemyController::update()
{
	if (m_player.expired())
	{
		return;
	}

	glm::vec3 moveDir = m_player.lock()->getTransform()->getLocalPosition() - getTransform()->getLocalPosition();

	moveDir.y = 0.0f;
	moveDir = glm::normalize(moveDir);

	getTransform()->translate(moveDir * m_movementSpeed);

}
void EnemyController::lateUpdate()
{

}