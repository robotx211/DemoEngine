#include <iostream>
#include <memory>

#include <myengine/myengine.h>
#include <game/Move.h>
#include <game/CameraController.h>

int main()
{

	std::shared_ptr<myEngine::Core> core = myEngine::Core::init();
	core->createNewWindowObject("main window", 1280, 720);

	//---------------------------------------create cube---------------------------------------

	std::shared_ptr<myEngine::Mesh> cubeMesh = std::make_shared<myEngine::Mesh>();
	cubeMesh->loadModel("../resources/cube.obj");

	std::shared_ptr<myEngine::Texture> cubeTex = std::make_shared<myEngine::Texture>();
	cubeTex->loadTexture("../resources/bricks.png");

	std::shared_ptr<myEngine::Sound> soundClip = std::make_shared<myEngine::Sound>();
	soundClip->loadSoundClip("../resources/dixie_horn.ogg");

	for (int x = -1; x <= 1; x++)
	{
		for (int y = -1; y <= 1; y++)
		{
			std::shared_ptr<myEngine::Entity> cube = core->addEntity();

			std::shared_ptr<myEngine::Transform> cube_transform = cube->addComponent<myEngine::Transform>();
			cube_transform->translate(4 * x, 4 * y, 0.0f);

			std::shared_ptr<myEngine::MeshRenderer> cube_renderer = cube->addComponent<myEngine::MeshRenderer>();
			cube_renderer->setMesh(cubeMesh);
			cube_renderer->setShaders("../resources/textured.vert", "../resources/textured.frag");
			cube_renderer->setTexture(cubeTex);

			std::shared_ptr<myEngine::BoxCollider> cube_collider = cube->addComponent<myEngine::BoxCollider>();

			if (x == 0 && y == 0)
			{
				std::shared_ptr<myEngine::RigidBody> cube_rb = cube->addComponent<myEngine::RigidBody>();

				std::shared_ptr<CameraController> cube_controller = cube->addComponent<CameraController>();
				cube_controller->setCameraSpeed(0.01f);
				cube_controller->setMovementSpeed(0.1f);
			}
		}
	}

	//---------------------------------------create main camera---------------------------------------

	std::shared_ptr<myEngine::Entity> maincamera = core->addEntity();

	std::shared_ptr<myEngine::Transform> maincamera_transform = maincamera->addComponent<myEngine::Transform>();

	maincamera_transform->translate(0.0f, 0.0f, 10.0f);

	std::shared_ptr<myEngine::Camera> maincamera_camera = maincamera->addComponent<myEngine::Camera>();

	maincamera_camera->setDegFOV(45.0f);
	maincamera_camera->setAspectRatio(core->getWindowObject()->getAspectRatio());

	//std::shared_ptr<CameraController> maincamera_controller = maincamera->addComponent<CameraController>();
	//maincamera_controller->setCameraSpeed(0.01f);
	//maincamera_controller->setMovementSpeed(0.1f);
	//maincamera_controller->setSound(soundClip);


	core->begin();

	return 0;
}
