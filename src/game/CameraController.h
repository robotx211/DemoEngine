#include <myengine/myengine.h>

class CameraController : public myEngine::Component
{

private:

	float m_speed;

	float m_yaw;
	float m_pitch;

	float m_pitchMin;
	float m_pitchMax;

public:

	CameraController();
	~CameraController();

	void start();
	void update();

	void setSpeed(float _speed) { m_speed = _speed; }
	float getSpeed() { return m_speed; }

	void setPitchLimits(float _min, float _max);
	void setYawLimits(float _min, float _max);

};