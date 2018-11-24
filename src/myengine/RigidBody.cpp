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
		m_collisions.clear();

		//get this collider
		std::shared_ptr<Collider> thisCollider = getEntity()->getComponent<Collider>();

		if (thisCollider == NULL)
		{
			return;
		}

		//get all colliders
		std::vector<std::shared_ptr<Collider>> allColliders;
		getCore()->getComponents<Collider>(&allColliders);

		for (size_t i = 0; i < allColliders.size(); i++)
		{
			if (allColliders.at(i) == thisCollider)
			{
				continue;
			}

			if (thisCollider->collide(allColliders.at(i)) == true)
			{
				m_colliding = true;
				m_collisions.push_back(allColliders.at(i));
			}

		}

		if (m_colliding == true)
		{
			std::cout << "Colliding: " << m_colliding << std::endl;
		}

		
	}

}