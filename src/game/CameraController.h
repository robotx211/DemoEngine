#ifndef CAMERA_CONTROLLER_H
#define CAMERA_CONTROLLER_H

#include <myengine/myengine.h>

class GameController;

class CameraController : public myEngine::Component
{

private:

	float m_cameraSpeed;
	float m_movementSpeed;

	float m_yaw;
	float m_pitch;

	float m_pitchMin;
	float m_pitchMax;

	std::shared_ptr<myEngine::Sound> m_sound;
	myEngine::Ray m_ray;

	int m_enemiesKilled;

	std::weak_ptr<GameController> m_gameController;

	bool m_spaceDown;
	bool m_nextPostProcess;

public:

	CameraController();
	~CameraController();

	void start();
	void update();
	void lateUpdate();

	int getKillCount() { return m_enemiesKilled; }
	void resetKillCount() { m_enemiesKilled = 0; }

	void setCameraSpeed(float _speed) { m_cameraSpeed = _speed; }
	float getCameraSpeed() { return m_cameraSpeed; }

	void setMovementSpeed(float _speed) { m_movementSpeed = _speed; }
	float getMovementSpeed() { return m_movementSpeed; }

	void setPitchLimits(float _min, float _max);

	void setSound(std::shared_ptr<myEngine::Sound> _sound) { m_sound = _sound; }

	void setGameController(std::shared_ptr<GameController> _game) { m_gameController = _game; }
};

#endif // !CAMERA_CONTROLLER_H