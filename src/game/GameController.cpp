#include <iostream>
#include <stdlib.h>
#include <time.h> 

#include "CameraController.h"
#include "GameController.h"
#include "EnemyController.h"

GameController::GameController()
{
	m_spawnTimer = 0.0f;

	m_maxEnemyCount = 10;
	m_spawnDelay = 5.0f;

	m_spawnPositions.clear();
}
GameController::~GameController()
{

}

void GameController::start()
{
	srand(time(NULL));

	m_spawnTimer = 0.0f;
}
void GameController::update()
{
	m_spawnTimer += getCore()->getEnviroment()->getDeltaTime() / 1000.0f;

	if (m_spawnTimer >= m_spawnDelay)
	{
		m_spawnTimer = 0.0f;
		//spawn();
	}
}

void GameController::spawn()
{
	for (int i = m_enemies.size() - 1; i >= 0; i--)
	{
		if (m_enemies.at(i).expired() == true)
		{
			m_enemies.erase(m_enemies.begin() + i);
		}
	}

	if (m_enemies.size() >= m_maxEnemyCount)
	{
		return;
	}

	int index = rand() % m_spawnPositions.size();

	spawnNewEnemy(m_spawnPositions.at(index));

	//std::cout << "Spawned Enemy! Count: " << m_enemies.size() << std::endl;

}

void GameController::spawnNewEnemy(glm::vec3 _pos)
{
	std::shared_ptr<myEngine::Entity> newenemy = getCore()->addEntity();
	newenemy->setName("enemy");

	std::shared_ptr<myEngine::Transform> newenemy_transform = newenemy->addComponent<myEngine::Transform>();
	newenemy_transform->translate(_pos);
	newenemy_transform->scale(0.5f, 0.5f, 0.5f);

	std::shared_ptr<myEngine::MeshRenderer> newenemy_renderer = newenemy->addComponent<myEngine::MeshRenderer>();
	newenemy_renderer->setMesh(&m_enemyMesh);
	newenemy_renderer->setShaders("../resources/textured.vert", "../resources/textured.frag");
	newenemy_renderer->setTexture(m_enemyTex);

	std::shared_ptr<myEngine::BoxCollider> newenemy_collider = newenemy->addComponent<myEngine::BoxCollider>();
	newenemy_collider->setScale(0.5f, 1.0f, 0.5f);

	std::shared_ptr<EnemyController> newenemy_controller = newenemy->addComponent<EnemyController>();
	newenemy_controller->setMovementSpeed(0.05f);
	newenemy_controller->setPlayer(m_player);

	m_enemies.push_back(newenemy_controller);
}

void GameController::reset()
{

	//reset player 

	m_player.lock()->getTransform()->setLocalPosition( glm::vec3(0.0f, 0.0f, 0.0f) );

	//destroy all enemies

	for (size_t i = 0; i < m_enemies.size(); i++)
	{
		m_enemies.at(i).lock()->getEntity()->markForDeletion();
	}


}