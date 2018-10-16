#ifndef MYENGINE_COMPONENT_H
#define MYENGINE_COMPONENT_H

#include <memory>
#include <vector>
#include <iostream>

namespace myEngine {

	class Core;
	class Entity;

	class Component
	{

	  friend class Entity;

	private:
	  std::weak_ptr<Component> m_self;
	  std::weak_ptr<Entity> m_entity;

	  virtual void onAwake();
	  virtual void onStart();
	  virtual void onUpdate();
	  virtual void onDisplay();

	  bool m_started;

	public:
	  std::shared_ptr<Entity> getEntity();
	  std::shared_ptr<Core> getCore();

	  void awake();
	  void start();
	  void update();
	  void display();

	};

}

#endif