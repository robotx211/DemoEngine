#include <memory>
#include <vector>

#include <glm/glm.hpp>

#include "Component.h"

namespace myEngine {

	class Transform : public Component
	{

	private:
		void onAwake();
		void onStart();
		void onUpdate();
		void onDisplay();

	public:
		glm::vec3 localPosition; //vec3
		glm::vec3 localRotation; //euler
		glm::vec3 localScale; //vec3

	};

}
