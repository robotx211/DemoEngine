#include <iostream>
#include <memory>

#include <myengine/myengine.h>

int main()
{

	std::shared_ptr<myEngine::Core> core = myEngine::Core::init();
	core->createNewWindowObject("main window", 1280, 720);

	//create camera

	std::shared_ptr<myEngine::Entity> camera = core->addEntity();

	camera->addComponent<myEngine::Transform>();

	camera->getComponent<myEngine::Transform>()->translate(glm::vec3(0.0f, 0.0f, 10.0f));

	camera->addComponent<myEngine::Camera>();

	camera->getComponent<myEngine::Camera>()->setDegFOV(45.0f);

	//create cube

	//std::shared_ptr<myEngine::Entity> cube = core->addEntity();

	//cube->addComponent<myEngine::Transform>();

	//std::shared_ptr<myEngine::Mesh> cubemesh = std::make_shared<myEngine::Mesh>();
	//cubemesh->loadModel("../resources/cube.obj");

	//cube->addComponent<myEngine::MeshRenderer>();
	//cube->getComponent<myEngine::MeshRenderer>()->setMesh(cubemesh);
	//cube->getComponent<myEngine::MeshRenderer>()->setShaders("../resources/simple.vert", "../resources/simple.frag");

	//cube->addComponent<myEngine::Move>();

	std::shared_ptr<myEngine::Entity> catman = core->addEntity();

	catman->addComponent<myEngine::Transform>();

	std::shared_ptr<myEngine::Mesh> catmesh = std::make_shared<myEngine::Mesh>();
	catmesh->loadModel("../resources/curuthers.obj");

	std::shared_ptr<myEngine::Texture> catTex = std::make_shared<myEngine::Texture>();
	catTex->loadTexture("../resources/curuthers_diffuse.png");

	catman->addComponent<myEngine::MeshRenderer>();
	catman->getComponent<myEngine::MeshRenderer>()->setMesh(catmesh);
	catman->getComponent<myEngine::MeshRenderer>()->setShaders("../resources/simple.vert", "../resources/simple.frag");
	catman->getComponent<myEngine::MeshRenderer>()->setTexture(catTex);

	catman->addComponent<myEngine::Move>();

	core->begin();

	std::cin.get();

	return 0;
}
