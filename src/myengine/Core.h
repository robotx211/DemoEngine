#include <memory>
#include <vector>
#include <iostream>

class Entity;

class Core
{

private:
  std::vector<std::shared_ptr<Entity>> entities;
  std::weak_ptr<Core> self;

public:
  static std::shared_ptr<Core> init();
  void start();
  void stop();
  std::shared_ptr<Entity> addEntity();

};
