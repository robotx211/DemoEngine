#ifndef TRANSFORM_H
#define TRANSFORM_H


#include <memory>
#include <vector>

#include <glm/glm.hpp>
#include <glm/ext.hpp>


#include "Component.h"

namespace myEngine {


	/**
	*	Transform Component
	*	Stores the Entity's position, orientation and scale
	*	Allows for translation, rotation and scaling of the Transform
	*/
	class Transform : public Component
	{

	private:

			glm::vec3 m_localPosition;

			glm::vec3 m_forward; ///< Forward direction for the transform
			glm::vec3 m_up; ///< Up direction for the transform
			glm::vec3 m_left; ///< Left direction for the transform

			glm::quat m_localOrientation;

			glm::vec3 m_localScale;


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

		void localAxisRotateQuaternion(glm::quat _quat); ///< Rotate about the entity's local axis
		void localAxisRotateQuaternion(float _angle, glm::vec3 _axis);
		void localAxisRotateQuaternion(float _angle, float _x, float _y, float _z);

		void localAxisRotateEulerRadians(glm::vec3 radians); ///< Rotate about the entity's local axis, using Euler Angles
		void localAxisRotateEulerRadians(float _x, float _y, float _z);

		void localAxisRotateEulerDegrees(glm::vec3 degrees);
		void localAxisRotateEulerDegrees(float _x, float _y, float _z);


		void worldAxisRotateQuaternion(glm::quat _quat); ///< Rotate about the world axis
		void worldAxisRotateQuaternion(float _angle, glm::vec3 _axis);
		void worldAxisRotateQuaternion(float _angle, float _x, float _y, float _z);

		void worldAxisRotateEulerRadians(glm::vec3 radians); ///< Rotate about the world axis, using Euler Angles
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
		glm::vec3 getUp() { return glm::normalize(m_up); }
		glm::vec3 getLeft() { return glm::normalize(m_left); }

	};

}

#endif // !TRANSFORM_H
