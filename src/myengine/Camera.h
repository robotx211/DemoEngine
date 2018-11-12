#ifndef CAMERA_H
#define CAMERA_H


#include <memory>
#include <vector>

#include <glm/glm.hpp>

#include "Component.h"
#include "Transform.h"

namespace myEngine
{

	class Camera : public Component
	{
	private:
		//rn just marks a transform as a camera

	public:

		void debug();

	};

}

#endif // !CAMERA_H