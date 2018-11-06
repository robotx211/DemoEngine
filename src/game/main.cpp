#include <iostream>
#include <memory>

#include <myengine/myengine.h>

int main()
{

  std::shared_ptr<myEngine::Core> core = myEngine::Core::init();
  core->createNewWindowObject("main window", 1280, 720);

  std::shared_ptr<myEngine::Entity> entity = core->addEntity("Triangle");

  //std::shared_ptr<myEngine::GL_Triangle> triangle = entity->addComponent<myEngine::GL_Triangle>();

  std::shared_ptr<myEngine::Mesh> mesh = std::make_shared<myEngine::Mesh>();
	mesh->loadModel("../resources/cube.obj");

	std::shared_ptr<myEngine::MeshRenderer> meshRenderer = entity->addComponent<myEngine::MeshRenderer>();
	meshRenderer->setMesh(mesh);
	meshRenderer->setShaders("../resources/VertexShader.txt", "../resources/FragmentShader.txt");

	core->begin();

  std::cin.get();

  return 0;
}
