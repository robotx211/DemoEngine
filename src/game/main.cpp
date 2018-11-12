#include <iostream>
#include <memory>

#include <myengine/myengine.h>

int main()
{

  std::shared_ptr<myEngine::Core> core = myEngine::Core::init();
  core->createNewWindowObject("main window", 1280, 720);

	//create camera

	std::shared_ptr<myEngine::Entity> camera = core->addEntity();

	std::shared_ptr<myEngine::Transform> camera_transform = camera->addComponent<myEngine::Transform>();

	camera_transform->translate(glm::vec3(0.0f, 0.0f, -3.0f));

	std::shared_ptr<myEngine::Camera> camera_camera = camera->addComponent<myEngine::Camera>();

	//create cube

 // std::shared_ptr<myEngine::Entity> cube = core->addEntity();

	//std::shared_ptr<myEngine::Transform> cube_transform = cube->addComponent<myEngine::Transform>();

 // std::shared_ptr<myEngine::Mesh> cubemesh = std::make_shared<myEngine::Mesh>();
	//cubemesh->loadModel("../resources/cube.obj");

	//std::shared_ptr<myEngine::MeshRenderer> cube_meshRenderer = cube->addComponent<myEngine::MeshRenderer>();
	//cube_meshRenderer->setMesh(cubemesh);
	//cube_meshRenderer->setShaders("../resources/simple.vert", "../resources/simple.frag");

	//create triangle

	std::shared_ptr<myEngine::Entity> GL_triangle = core->addEntity();

	std::shared_ptr<myEngine::GL_Triangle> GL_triangle_renderer = GL_triangle->addComponent<myEngine::GL_Triangle>();

	core->begin();

  std::cin.get();

  return 0;
}
