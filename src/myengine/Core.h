#include <memory>
#include <vector>
#include <iostream>

class Entity;

class Core
{

private:
  std::vector<std::shared_ptr<Entity>> entities;

public:
  void start();
  void stop();
  std::shared_ptr<Entity> addEntity();

};
