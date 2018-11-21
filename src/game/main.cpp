#include <iostream>
#include <memory>

#include <myengine/myengine.h>

int main()
{

	std::shared_ptr<myEngine::Core> core = myEngine::Core::init();
	core->createNewWindowObject("main window", 1280, 720);

	//create cube

	std::shared_ptr<myEngine::Mesh> cubeMesh = std::make_shared<myEngine::Mesh>();
	cubeMesh->loadModel("../resources/cube.obj");

	std::shared_ptr<myEngine::Texture> cubeTex = std::make_shared<myEngine::Texture>();
	cubeTex->loadTexture("../resources/bricks.png");

	std::shared_ptr<myEngine::Entity> cube = core->addEntity();

	std::shared_ptr<myEngine::Transform> cube_transform = cube->addComponent<myEngine::Transform>();
	cube_transform->translate(4.0f, 0.0f, 0.0f);

	std::shared_ptr<myEngine::MeshRenderer> cube_renderer = cube->addComponent<myEngine::MeshRenderer>();
	cube_renderer->setMesh(cubeMesh);
	cube_renderer->setShaders("../resources/textured.vert", "../resources/textured.frag");
	cube_renderer->setTexture(cubeTex);

	cube->addComponent<myEngine::Move>();

	//create a render screen
	
	std::shared_ptr<myEngine::Mesh> screenMesh = std::make_shared<myEngine::Mesh>();
	screenMesh->loadModel("../resources/square.obj");

	std::shared_ptr<myEngine::RenderTexture> screenrenderTex = std::make_shared<myEngine::RenderTexture>();
	screenrenderTex->setSize(256, 256);
	screenrenderTex->init();

	std::shared_ptr<myEngine::Entity> screen = core->addEntity();

	std::shared_ptr<myEngine::Transform> screen_transform = screen->addComponent<myEngine::Transform>();
	screen_transform->translate(0.0f, 0.0f, -10.0f);
	screen_transform->translate(-20.0f, 0.0f, 0.0f);
	screen_transform->rotateEulerDegrees(180.0f, 0.0f, 0.0f);
	screen_transform->scale(10.0f, 10.0f, 1.0f);

	std::shared_ptr<myEngine::MeshRenderer> screen_renderer = screen->addComponent<myEngine::MeshRenderer>();
	screen_renderer->setMesh(screenMesh);
	screen_renderer->setShaders("../resources/textured.vert", "../resources/textured.frag");

	screen_renderer->setTexture(screenrenderTex);

	//create render camera

	std::shared_ptr<myEngine::Entity> rendercamera = core->addEntity();

	std::shared_ptr<myEngine::Transform> rendercamera_transform = rendercamera->addComponent<myEngine::Transform>();

	rendercamera_transform->translate(4.0f, 0.0f, 3.0f);

	std::shared_ptr<myEngine::Camera> rendercamera_camera = rendercamera->addComponent<myEngine::Camera>();

	rendercamera_camera->setDegFOV(45.0f);
	rendercamera_camera->setRenderTexture(screenrenderTex);

	//create main camera

	std::shared_ptr<myEngine::Entity> maincamera = core->addEntity();

	std::shared_ptr<myEngine::Transform> maincamera_transform = maincamera->addComponent<myEngine::Transform>();

	maincamera_transform->translate(-20.0f, 0.0f, 10.0f);

	std::shared_ptr<myEngine::Camera> maincamera_camera = maincamera->addComponent<myEngine::Camera>();

	maincamera_camera->setDegFOV(45.0f);

	core->begin();

	return 0;
}
