#include <memory>
#include <vector>

class Core;
class Component;

class Entity
{

private:
  std::vector<std::shared_ptr<Component>> components;
  std::weak_ptr<Core> core;

  void tick();
  void display();

public:
  void setCore(std::shared_ptr<Core> _core);
  std::shared_ptr<Core> getCore();
  template <class T> std::shared_ptr<T> addComponent(T _type);
  //add more for initialisation parameters

};

