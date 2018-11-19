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

	camera_transform->translate(glm::vec3(0.0f, 0.0f, 10.0f));

	std::shared_ptr<myEngine::Camera> camera_camera = camera->addComponent<myEngine::Camera>();

	camera_camera->setDegFOV(45.0f);

	//create cube

	std::shared_ptr<myEngine::Entity> cube = core->addEntity();

	cube->addComponent<myEngine::Transform>();

	std::shared_ptr<myEngine::Mesh> cubeMesh = std::make_shared<myEngine::Mesh>();
	cubeMesh->loadModel("../resources/cube.obj");

	std::shared_ptr<myEngine::Texture> cubeTex = std::make_shared<myEngine::Texture>();
	cubeTex->loadTexture("../resources/bricks.png");

	std::shared_ptr<myEngine::MeshRenderer> cube_renderer = cube->addComponent<myEngine::MeshRenderer>();
	cube_renderer->setMesh(cubeMesh);
	cube_renderer->setShaders("../resources/textured.vert", "../resources/textured.frag");
	cube_renderer->setTexture(cubeTex);

	cube->addComponent<myEngine::Move>();

	core->begin();

	return 0;
}
