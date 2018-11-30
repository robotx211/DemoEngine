#ifndef RIGID_BODY_H
#define RIGID_BODY_H

#include <memory>
#include <vector>

#include "Component.h"
#include "Collider.h"

namespace myEngine
{

	/**
	*	Component which performs collision checking for the Entity's collider against all other colliders in the scene, and stores pointers to the colliders
	*/
	class RigidBody : public Component
	{

	private:

		bool m_colliding;
		std::vector<std::shared_ptr<Collider>> m_collisions;


	public:

		RigidBody();
		~RigidBody();

		void physicsUpdate();

		bool isColliding() { return m_colliding; }
		std::vector<std::shared_ptr<Collider>> getCollisions() { return m_collisions; }

	};

}

#endif // !RIGID_BODY_H
