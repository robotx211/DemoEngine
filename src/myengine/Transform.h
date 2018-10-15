#include <memory>
#include <vector>

#include <glm/glm.hpp>

#include "Component.h"

class Transform : public Component
{

private:

public:
  glm::vec3 localPosition; //vec3
  glm::vec3 localRotation; //euler
  glm::vec3 localScale; //vec3

};
