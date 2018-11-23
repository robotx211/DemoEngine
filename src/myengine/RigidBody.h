#ifndef RIGID_BODY_H
#define RIGID_BODY_H

#include "Component.h"
#include "Collider.h"

namespace myEngine
{

	class RigidBody : public Component
	{

	private:

		bool m_colliding;


	public:

		RigidBody();
		~RigidBody();

		void physicsUpdate();



	};

}

#endif // !RIGID_BODY_H
