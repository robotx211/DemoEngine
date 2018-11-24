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

	bool Collider::rayCollide(glm::vec3 _origin, glm::vec3 _direction)
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
			if (aPos.x + aSize.x > bPos.x - bSize.x) //is axMax > bxMin
			{
				xCheck = true;
			}
		}
		else //aPos.x >= bPos.x
		{
			if (bPos.x + bSize.x > aPos.x - aSize.x) //is bxMax > axMin
			{
				xCheck = true;
			}
		}

		if (aPos.y < bPos.y)
		{
			if (aPos.y + aSize.y > bPos.y - bSize.y)
			{
				yCheck = true;
			}
		}
		else //aPos.y >= bPos.y
		{
			if (bPos.y + bSize.y > aPos.y - aSize.y)
			{
				yCheck = true;
			}
		}

		if (aPos.z < bPos.z)
		{
			if (aPos.z + aSize.z > bPos.z - bSize.z)
			{
				zCheck = true;
			}
		}
		else //aPos.z >= bPos.z
		{
			if (bPos.z + bSize.z > aPos.z - aSize.z)
			{
				zCheck = true;
			}
		}

		bool returnBool = (xCheck && yCheck && zCheck);

		return returnBool;

	}

	bool BoxCollider::rayCollide(glm::vec3 _o, glm::vec3 _d)
	{
		//https://www.scratchapixel.com/lessons/3d-basic-rendering/minimal-ray-tracer-rendering-simple-shapes/ray-box-intersection

		std::shared_ptr<Transform> trans = getTransform();
		glm::vec3 pos = trans->getLocalPosition();
		glm::vec3 size = (trans->getLocalScale() * m_scale) / 2.0f;

		glm::vec3 min = pos - size;
		glm::vec3 max = pos + size;

		float tMin = (min.x - _o.x) / _d.x;
		float tMax = (max.x - _o.x) / _d.x;

		if (tMin > tMax)
		{
			float tmp = tMax;
			tMax = tMin;
			tMin = tmp;
		}

		float tMinY = (min.y - _o.y) / _d.y;
		float tMaxY = (max.y - _o.y) / _d.y;

		if (tMinY > tMaxY)
		{
			float tmp = tMaxY;
			tMaxY = tMinY;
			tMinY = tmp;
		}

		if ((tMin > tMaxY) || (tMinY > tMax))
		{
			return false;
		}

		if (tMinY > tMin)
		{
			tMin = tMinY;
		}

		if (tMaxY < tMax)
		{
			tMax = tMaxY;
		}

		float tMinZ = (min.z - _o.z) / _d.z;
		float tMaxZ = (max.z - _o.z) / _d.z;

		if (tMinZ > tMaxZ)
		{
			float tmp = tMaxZ;
			tMaxZ = tMinZ;
			tMinZ = tmp;
		}

		if ((tMin > tMaxZ) || (tMinZ > tMax))
		{
			return false;
		}

		if (tMinZ > tMin)
		{
			tMin = tMinZ;
		}

		if (tMaxZ < tMax)
		{
			tMax = tMaxZ;
		}

		return true;
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

