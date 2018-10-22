#include <glm/glm.hpp>
#include <vector>
#include <memory>

class Mesh
{

private:
  std::shared_ptr<std::vector<glm::vec3>> m_vertexPositions;

public:
  std::shared_ptr<std::vector<glm::vec3>> getVetrices() { return m_vertexPositions; }

};