#ifndef CAMERA_H
#define CAMERA_H


#include <memory>
#include <vector>

#include <glm/glm.hpp>

#include "Component.h"

namespace myEngine
{

	class Camera : public Component
	{
	private:
		
		float m_DegFOV;


	public:

		Camera();
		~Camera();

		void setDegFOV(float _value); //in degrees

		glm::mat4 getViewMatrix();
		float getRadFOV();

		void debug();
	};

}

#endif // !CAMERA_H