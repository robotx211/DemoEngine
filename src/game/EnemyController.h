#ifndef ENEMY_CONTROLLER_H
#define ENEMY_CONTROLLER_H

#include <myengine/myengine.h>

#include <memory>

class CameraController;

class EnemyController : public myEngine::Component
{

	

private:

	std::weak_ptr<CameraController> m_player;

	float m_movementSpeed;

	void setSound(std::shared_ptr<myEngine::Sound> _sound) { m_sound = _sound; }
	std::shared_ptr<myEngine::Sound> m_sound;

public:

	EnemyController();
	~EnemyController();

	void start();
	void update();
	void lateUpdate();

	void setPlayer(std::shared_ptr<CameraController> _player) { m_player = _player; }
	void setPlayer(std::weak_ptr<CameraController> _player) { m_player = _player; }

	void setMovementSpeed(float _speed) { m_movementSpeed = _speed; }
	float getMovementSpeed() { return m_movementSpeed; }

};


#endif // !ENEMY_CONTROLLER_H