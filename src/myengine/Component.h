#include <memory>
#include <vector>
#include <iostream>


class Core;
class Entity;

class Component
{

private:
  std::weak_ptr<Entity> entity;

  virtual void onInit();
  virtual void onBegin();
  virtual void onTick();
  virtual void onDisplay();

public:
  std::shared_ptr<Entity> getEntity();
  std::shared_ptr<Core> getCore();

  void tick();
  void display();

};
