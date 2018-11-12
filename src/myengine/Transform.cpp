#include "Transform.h"

namespace myEngine {

	Transform::Transform()
	{
		m_localPosition = glm::vec3(0.0);
		m_localRotation = glm::vec3(0.0);
		m_localScale = glm::vec3(0.0);
	}

	Transform::Transform(glm::vec3 _pos, glm::vec3 _rot, glm::vec3 _sca)
	{
		m_localPosition = _pos;
		m_localRotation = _rot;
		m_localScale = _sca;
	}

	glm::vec3 Transform::localPosition()
	{
		return m_localPosition;
	}
	void Transform::localPosition(glm::vec3 _pos)
	{
		m_localPosition = _pos;
	}

	void Transform::translate(glm::vec3 _vec)
	{
		m_localPosition += _vec;
	}
	void Transform::translate(float _x, float _y, float _z)
	{
		translate(glm::vec3(_x, _y, _z));
	}

	glm::vec3 Transform::localRotation()
	{
		return m_localRotation;
	}
	void Transform::localRotation(glm::vec3 _rot)
	{
		m_localRotation = _rot;
	}

	void Transform::rotate(glm::vec3 _vec)
	{
		m_localRotation += _vec;
	}
	void Transform::rotate(float _x, float _y, float _z)
	{
		rotate(glm::vec3(_x, _y, _z));
	}

	glm::vec3 Transform::localScale()
	{
		return m_localScale;
	}
	void Transform::localScale(glm::vec3 _sca)
	{
		m_localScale = _sca;
	}

	void Transform::scale(glm::vec3 _vec)
	{
		m_localScale += _vec;
	}
	void Transform::scale(float _x, float _y, float _z)
	{
		scale(glm::vec3(_x, _y, _z));
	}

  void Transform::debug()
  {
    std::cout << "    Transform" << std::endl;
  }



}