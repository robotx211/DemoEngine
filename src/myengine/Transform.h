#include <memory>
#include <vector>

#include <glm/glm.hpp>

#include "Component.h"

namespace myEngine {

	class Transform : public Component
	{

	private:

			glm::vec3 m_localPosition; //vec3
			glm::vec3 m_localRotation; //euler
			glm::vec3 m_localScale; //vec3

	public:

		Transform();
		Transform(glm::vec3 _pos, glm::vec3 _rot, glm::vec3 _sca);
		~Transform();

		glm::vec3 localPosition();
		void localPosition(glm::vec3 _pos);

		void translate(glm::vec3 _vec);
		void translate(float _x, float _y, float _z);

		glm::vec3 localRotation();
		void localRotation(glm::vec3 _rot);

		void rotate(glm::vec3 _vec);
		void rotate(float _x, float _y, float _z);

		glm::vec3 localScale();
		void localScale(glm::vec3 _sca);

		void scale(glm::vec3 _vec);
		void scale(float _x, float _y, float _z);

		void debug();

	};

}
