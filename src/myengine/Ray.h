#ifndef RAY_H
#define RAY_H

#include <memory>
#include <vector>
#include <glm/glm.hpp>

#include "Core.h"
#include "Collider.h"

namespace myEngine
{

	/**
	*	Performs ray collider checks against all colliders in the scene, stores pointers to the colliders
	*/
	class Ray
	{

	private:

		std::weak_ptr<Core> m_corePtr;

		glm::vec3 m_origin;
		glm::vec3 m_direction;

		bool m_hit;
		std::vector<std::shared_ptr<Collider>> m_collisions;

	public:

		Ray();
		Ray(std::weak_ptr<Core> _core, glm::vec3 _origin, glm::vec3 _direction);
		~Ray();

		void setCore(std::weak_ptr<Core> _core) { m_corePtr = _core; }
		void setOrigin(glm::vec3 _origin) { m_origin = _origin; }
		void setDirection(glm::vec3 _direction) { m_direction = _direction; }

		bool rayCast();

		bool didHit() { return m_hit; }
		std::vector<std::shared_ptr<Collider>> getCollisions() { return m_collisions; }


	};

}

#endif // !RAY_H
