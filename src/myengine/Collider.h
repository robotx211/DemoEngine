#ifndef COLLIDER_H
#define COLLIDER_H

//using bounding boxes and AABB collision

#include <glm/glm.hpp>

#include "Component.h"

namespace myEngine
{

	class Collider : public Component
	{
	private:

	public:
		Collider();
		~Collider();

		virtual bool collide(std::shared_ptr<Collider> _c);

		virtual bool rayCollide(glm::vec3 _o, glm::vec3 _d);

		virtual void display();
	};

	class BoxCollider : public Collider
	{
	private:
		glm::vec3 m_scale; //scale
	public:
		BoxCollider();
		~BoxCollider();

		void setScale(glm::vec3 _size) { m_scale = _size; }
		void setScale(float _x, float _y, float _z) { setScale(glm::vec3(_x, _y, _z)); }

		bool collide(std::shared_ptr<Collider> _collider);
		bool collide(std::shared_ptr<BoxCollider> _collider);

		bool rayCollide(glm::vec3 _o, glm::vec3 _d);

		//might do later is time allows
		void display();
		void draw();

	};

}

#endif // !COLLIDER_H
