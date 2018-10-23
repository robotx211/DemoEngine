#include <memory>
#include <vector>

#include <glm/glm.hpp>

#include "Component.h"

namespace myEngine {

	class Transform : public Component
	{

	private:

      void debug();

	public:

	  glm::vec3 m_localPosition; //vec3
	  glm::vec3 m_localOrientation; //euler
	  glm::vec3 m_localScale; //vec3

	};

}
