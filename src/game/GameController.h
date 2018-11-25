#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include <myengine/myengine.h>

#include <memory>
#include <vector>
#include <glm/glm.hpp>

class CameraController;
class EnemyController;

class GameController : public myEngine::Component
{

private:

	int m_maxEnemyCount;

	std::weak_ptr<CameraController> m_player;
	std::vector < std::weak_ptr<EnemyController> > m_enemies;

	float m_spawnTimer;
	float m_spawnDelay;

	std::vector<glm::vec3> m_spawnPositions;

	//enemy spawning data
	std::shared_ptr<myEngine::Mesh> m_enemyMesh;
	std::shared_ptr<myEngine::Texture> m_enemyTex;
	std::shared_ptr<myEngine::Sound> m_enemySound;

public:

	GameController();
	~GameController();

	void start();
	void update();

	void spawn();
	void spawnNewEnemy(glm::vec3 _pos);

	void reset();

	void setPlayer(std::shared_ptr<CameraController> _player) { m_player = _player; }

	void setMaxEnemyCount(int _max) { m_maxEnemyCount = _max; }

	void setSpawnDelay(float _delay) { m_spawnDelay = _delay; }

	void addSpawnPosition(glm::vec3 _spawnPosition) { m_spawnPositions.push_back(_spawnPosition); }
	void setSpawnPositions(std::vector<glm::vec3> _spawnPositions) { m_spawnPositions = _spawnPositions; }
	void clearSpawnPositions() { m_spawnPositions.clear(); }

	void setEnemyMesh(std::shared_ptr<myEngine::Mesh> _mesh) { m_enemyMesh = _mesh; }
	void setEnemyTex(std::shared_ptr<myEngine::Texture> _tex) { m_enemyTex = _tex; }
	void setEnemySound(std::shared_ptr<myEngine::Sound> _sound) { m_enemySound = _sound; }

};

#endif // !GAME_CONTROLLER_H