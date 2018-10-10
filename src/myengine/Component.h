#include <memory>
#include <vector>
#include <iostream>


class Core;
class Entity;

class Component
{

private:
  std::weak_ptr<Entity> entity;

  virtual void onAwake();
  virtual void onStart();
  virtual void onUpdate();
  virtual void onDisplay();

public:
  void setEntity(std::shared_ptr<Entity> _entity);
  std::shared_ptr<Entity> getEntity();
  std::shared_ptr<Core> getCore();
  
  void awake();
  void start();
  void update();
  void display();

};
