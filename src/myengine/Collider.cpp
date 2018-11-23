#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "Transform.h"
#include "Collider.h"

namespace myEngine
{

#pragma region Collider

	Collider::Collider()
	{
		
	}
	Collider::~Collider()
	{

	}

	bool Collider::collide(std::shared_ptr<Collider> _c)
	{
		//should never check against this
		throw std::exception();
	}

	void Collider::display()
	{

	}


#pragma endregion


#pragma region BoxCollider
		//BoxCollider

	BoxCollider::BoxCollider()
	{
		m_scale = glm::vec3(1.0f, 1.0f, 1.0f);
	}
	BoxCollider::~BoxCollider()
	{

	}

	bool BoxCollider::collide(std::shared_ptr<Collider> _collider)
	{
		std::shared_ptr<BoxCollider> tryBoxCollider = std::static_pointer_cast<BoxCollider, Collider>(_collider);

		if (tryBoxCollider != NULL)
		{
			return collide(tryBoxCollider);
		}

		//passed pointer was base Collider
		return false;

	}
	bool BoxCollider::collide(std::shared_ptr<BoxCollider> _collider)
	{
		//should profile this

		//a = this
		//b = _collider

		//a.x = this.transform.position.x
		//b.x = _collider.transform.position.x

		//a.width => a.xScale = this.transform.scale.x * this.scale
		//b.width => b.xScale = _collider.transform.scale.x * _collider.scale

		std::shared_ptr<Transform> aTrans = getTransform();
		std::shared_ptr<Transform> bTrans = _collider->getTransform();

		glm::vec3 aPos = aTrans->getLocalPosition();
		glm::vec3 bPos = bTrans->getLocalPosition();

		//for now, no rotation

		glm::vec3 aSize = (aTrans->getLocalScale() * m_scale) / 2.0f;
		glm::vec3 bSize = (bTrans->getLocalScale() * m_scale) / 2.0f;

		//note assume base size is 1 by 1 by 1

		bool xCheck = false;
		bool yCheck = false;
		bool zCheck = false;

		if (aPos.x < bPos.x)
		{
			if (aPos.x + aSize.x < bPos.x)
			{
				xCheck = true;
			}
		}
		else //aPos.x >= bPos.x
		{
			if (bPos.x + bSize.x < aPos.x)
			{
				xCheck = true;
			}
		}

		if (aPos.y < bPos.y)
		{
			if (aPos.y + aSize.y < bPos.y)
			{
				yCheck = true;
			}
		}
		else //aPos.y >= bPos.y
		{
			if (bPos.y + bSize.y < aPos.y)
			{
				yCheck = true;
			}
		}

		if (aPos.z < bPos.z)
		{
			if (aPos.z + aSize.z < bPos.z)
			{
				zCheck = true;
			}
		}
		else //aPos.z >= bPos.z
		{
			if (bPos.z + bSize.z < aPos.z)
			{
				zCheck = true;
			}
		}

		bool returnBool = (xCheck && yCheck && zCheck);

		return returnBool;

	}

	void BoxCollider::display()
	{
		draw();
	}
	void BoxCollider::draw()
	{

	}
#pragma endregion

#pragma region MeshCollider

#pragma endregion


}

