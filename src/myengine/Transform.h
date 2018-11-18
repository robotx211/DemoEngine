#ifndef TRANSFORM_H
#define TRANSFORM_H


#include <memory>
#include <vector>

#include <glm/glm.hpp>
#include <glm/ext.hpp>


#include "Component.h"

namespace myEngine {

	class Transform : public Component
	{

	private:

			glm::vec3 m_localPosition; //vec3
			glm::quat m_localOrientation; //quaternions
			glm::vec3 m_localScale; //vec3

	public:

		Transform();
		Transform(glm::vec3 _pos, glm::vec3 _sca);
		~Transform();

		//-------------TRANSLATION-------------

		glm::vec3 getLocalPosition();
		void setLocalPosition(glm::vec3 _pos);

		void translate(glm::vec3 _vec);
		void translate(float _x, float _y, float _z);

		//-------------TRANSLATION-------------

		//-------------ROTATION-------------

		glm::quat getLocalOrientation();
		void setLocalOrientation(glm::quat _orient);

		void rotateQuaternion(glm::quat _quat);
		void rotateQuaternion(float _angle, glm::vec3 _axis);
		void rotateQuaternion(float _angle, float _x, float _y, float _z);

		void Transform::rotateEulerRadians(glm::vec3 radians);
		void Transform::rotateEulerDegrees(glm::vec3 degrees);

		//-------------ROTATION-------------

		//-------------SCALE-------------

		glm::vec3 getLocalScale();
		void setLocalScale(glm::vec3 _sca);

		void scale(glm::vec3 _vec);
		void scale(float _x, float _y, float _z);

		//-------------SCALE-------------



		glm::mat4 getTransformMat();

		void debug();

	};

}

#endif // !TRANSFORM_H
