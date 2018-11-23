#include <memory>
#include <vector>

#include "RigidBody.h"

namespace myEngine
{

	RigidBody::RigidBody()
	{

	}
	RigidBody::~RigidBody()
	{

	}

	void RigidBody::physicsUpdate()
	{

		m_colliding = false;

		//get this collider
		std::shared_ptr<Collider> thisCollider = getEntity()->getComponent<Collider>();

		//get all colliders
		std::vector<std::shared_ptr<Collider>> allColliders;
		getCore()->getComponents<Collider>(&allColliders);

		for (size_t i = 0; i < allColliders.size(); i++)
		{
			if (allColliders.at(i) == thisCollider)
			{
				continue;
			}

			m_colliding = thisCollider->collide(allColliders.at(i));

			if (m_colliding == true)
			{
				continue;
			}

		}
	}

}