#include <glm/glm.hpp>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>

#include "Ray.h"
#include "Transform.h"

namespace myEngine
{

	Ray::Ray()
	{

	}
	Ray::Ray(std::weak_ptr<Core> _core, glm::vec3 _origin, glm::vec3 _direction)
	{
		m_corePtr = _core;
		m_origin = _origin;
		m_direction = _direction;

		m_hit = false;
		m_collisions.clear();
	}
	Ray::~Ray()
	{
		m_collisions.clear();
	}

	bool Ray::rayCast()
	{
		m_hit = false;
		m_collisions.clear(); 

		//get all colliders
		std::vector<std::shared_ptr<Collider>> allColliders;
		m_corePtr.lock()->getComponents<Collider>(&allColliders);

		for (size_t i = 0; i < allColliders.size(); i++)
		{
			if (allColliders.at(i)->rayCollide(m_origin, m_direction) == true)
			{
				m_hit = true;
				m_collisions.push_back(allColliders.at(i));
			}
		}

		//if (m_hit == true)
		//{
		//	std::cout << "Hit: " << m_collisions.size() << std::endl;

		//	for (size_t i = 0; i < m_collisions.size(); i++)
		//	{
		//		std::cout << "\tPos: " << glm::to_string(m_collisions.at(i)->getTransform()->getLocalPosition()) << std::endl;
		//	}

		//}

		return m_hit;
	}

}