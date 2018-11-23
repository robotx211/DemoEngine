#include <myengine/myengine.h>

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

public:

	CameraController();
	~CameraController();

	void start();
	void update();

	void setCameraSpeed(float _speed) { m_cameraSpeed = _speed; }
	float getCameraSpeed() { return m_cameraSpeed; }

	void setMovementSpeed(float _speed) { m_movementSpeed = _speed; }
	float getMovementSpeed() { return m_movementSpeed; }

	void setPitchLimits(float _min, float _max);

	void setSound(std::shared_ptr<myEngine::Sound> _sound) { m_sound = _sound; }

};