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

			glm::vec3 m_forward;
			//glm::vec3 m_up;
			//glm::vec3 m_left;

			glm::quat m_localOrientation; //quaternions

			glm::vec3 m_localScale; //vec3


	public:

		Transform();
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

		void localAxisRotateQuaternion(glm::quat _quat);
		void localAxisRotateQuaternion(float _angle, glm::vec3 _axis);
		void localAxisRotateQuaternion(float _angle, float _x, float _y, float _z);

		void localAxisRotateEulerRadians(glm::vec3 radians);
		void localAxisRotateEulerRadians(float _x, float _y, float _z);

		void localAxisRotateEulerDegrees(glm::vec3 degrees);
		void localAxisRotateEulerDegrees(float _x, float _y, float _z);


		void worldAxisRotateQuaternion(glm::quat _quat);
		void worldAxisRotateQuaternion(float _angle, glm::vec3 _axis);
		void worldAxisRotateQuaternion(float _angle, float _x, float _y, float _z);

		void worldAxisRotateEulerRadians(glm::vec3 radians);
		void worldAxisRotateEulerRadians(float _x, float _y, float _z);

		void worldAxisRotateEulerDegrees(glm::vec3 degrees);
		void worldAxisRotateEulerDegrees(float _x, float _y, float _z);

		//-------------ROTATION-------------

		//-------------SCALE-------------

		glm::vec3 getLocalScale();
		void setLocalScale(glm::vec3 _sca);

		void scale(glm::vec3 _vec);
		void scale(float _x, float _y, float _z);

		//-------------SCALE-------------



		glm::mat4 getTransformMat();

		void debug();

		void checkDirections();

		glm::vec3 getForward() { return glm::normalize(m_forward); }

	};

}

#endif // !TRANSFORM_H
