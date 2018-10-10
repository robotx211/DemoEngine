#include <memory>
#include <vector>

#include "Component.h"

class Core;

class Entity
{

private:
  std::vector<std::shared_ptr<Component>> components;
  std::weak_ptr<Core> core;

  void update();
  void display();

public:
  void setCore(std::shared_ptr<Core> _core);
  std::shared_ptr<Core> getCore();
  template <typename T> std::shared_ptr<T> addComponent()
  {
    std::shared_ptr<T> newComponent = std::make_shared<T>();

    components.push_back(newComponent);

    return newComponent;
  }


  //add more for initialisation parameters


};

