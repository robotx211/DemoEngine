#ifndef MYENGINE_COMPONENT_H
#define MYENGINE_COMPONENT_H

#include <memory>
#include <vector>
#include <iostream>

class Core;
class Entity;

class Component
{

  friend class Entity;

private:
  std::weak_ptr<Component> self;
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

#endif