#include <iostream>
#include <memory>

#include <myengine/myengine.h>
#include <game/Move.h>
#include <myengine/GL_Triangle.h>

#include <game/GameController.h>
#include <game/CameraController.h>
#include <game/EnemyController.h>

int main()
{

	std::shared_ptr<myEngine::Core> core = myEngine::Core::init();
	core->createNewWindowObject("main window", 1280, 720);

	//---------------------------------------create main camera / player---------------------------------------

	std::shared_ptr<myEngine::Entity> maincamera = core->addEntity();
	maincamera->setName("player");

	std::shared_ptr<myEngine::Transform> maincamera_transform = maincamera->addComponent<myEngine::Transform>();

	maincamera_transform->translate(0.0f, 0.0f, 0.0f);

	std::shared_ptr<myEngine::Camera> maincamera_camera = maincamera->addComponent<myEngine::Camera>();

	maincamera_camera->setDegFOV(45.0f);
	maincamera_camera->setAspectRatio(core->getWindowObject()->getAspectRatio());

	std::shared_ptr<CameraController> maincamera_controller = maincamera->addComponent<CameraController>();
	maincamera_controller->setCameraSpeed(0.01f);
	maincamera_controller->setMovementSpeed(0.1f);

	maincamera->addComponent<myEngine::BoxCollider>();

	maincamera->addComponent<myEngine::RigidBody>();

	//---------------------------------------create game controller---------------------------------------

	std::shared_ptr<myEngine::Entity> gamecontroller = core->addEntity();

	std::shared_ptr<GameController> gamecontroller_controller = gamecontroller->addComponent<GameController>();

	gamecontroller_controller->setPlayer(maincamera_controller);
	maincamera_controller->setGameController(gamecontroller_controller);

	//---------------------------------------create enemy resources---------------------------------------

	std::shared_ptr<myEngine::Mesh> cubeMesh = std::make_shared<myEngine::Mesh>();
	cubeMesh->loadModel("../resources/cube.obj");

	std::shared_ptr<myEngine::Texture> cubeTex = std::make_shared<myEngine::Texture>();
	cubeTex->loadTexture("../resources/bricks.png");

	std::shared_ptr<myEngine::Sound> soundClip = std::make_shared<myEngine::Sound>();
	soundClip->loadSoundClip("../resources/dixie_horn.ogg");

	//---------------------------------------assign enemy resources to game controller---------------------------------------

	gamecontroller_controller->setEnemyMesh(cubeMesh);
	gamecontroller_controller->setEnemyTex(cubeTex);
	gamecontroller_controller->setEnemySound(soundClip);

	gamecontroller_controller->addSpawnPosition(glm::vec3(0.0f, 0.0f, 30.0f));
	gamecontroller_controller->addSpawnPosition(glm::vec3(0.0f, 0.0f, -30.0f));
	gamecontroller_controller->addSpawnPosition(glm::vec3(30.0f, 0.0f, 0.0f));
	gamecontroller_controller->addSpawnPosition(glm::vec3(-30.0f, 0.0f, 0.0f));

	gamecontroller_controller->addSpawnPosition(glm::vec3(30.0f, 0.0f, 30.0f));
	gamecontroller_controller->addSpawnPosition(glm::vec3(30.0f, 0.0f, -30.0f));
	gamecontroller_controller->addSpawnPosition(glm::vec3(-30.0f, 0.0f, 30.0f));
	gamecontroller_controller->addSpawnPosition(glm::vec3(-30.0f, 0.0f, -30.0f));

	gamecontroller_controller->setSpawnDelay(1.0f);
	gamecontroller_controller->setMaxEnemyCount(10);

	//---------------------------------------create world---------------------------------------

	std::shared_ptr<myEngine::Mesh> squareMesh = std::make_shared<myEngine::Mesh>();
	squareMesh->loadModel("../resources/square.obj");

	std::shared_ptr<myEngine::Texture> floorTex = std::make_shared<myEngine::Texture>();
	floorTex->loadTexture("../resources/floor.png");

	for (int x = -3; x <= 3; x++)
	{
		for (int z = -3; z <= 3; z++)
		{
			std::shared_ptr<myEngine::Entity> floor = core->addEntity();

			std::shared_ptr<myEngine::Transform> floor_transform = floor->addComponent<myEngine::Transform>();
			floor_transform->translate(10.0f * x, 1.0f, 10.0f * z);
			floor_transform->scale(10.0f, 10.0f, 0.0f);
			floor_transform->localAxisRotateEulerDegrees(90, 0.0f, 0.0f);

			std::shared_ptr<myEngine::MeshRenderer> floor_renderer = floor->addComponent<myEngine::MeshRenderer>();
			floor_renderer->setMesh(squareMesh);
			floor_renderer->setShaders("../resources/textured.vert", "../resources/textured.frag");
			floor_renderer->setTexture(floorTex);
		}
	}

	std::shared_ptr<myEngine::Texture> wallTex = std::make_shared<myEngine::Texture>();
	wallTex->loadTexture("../resources/wall.png");

	for (int z = -3; z <= 3; z++)
	{
		std::shared_ptr<myEngine::Entity> wall = core->addEntity();

		std::shared_ptr<myEngine::Transform> wall_transform = wall->addComponent<myEngine::Transform>();
		wall_transform->translate(35.0f, -1.0f, 10.0f * z);
		wall_transform->scale(10.0f, 10.0f, 0.0f);
		wall_transform->localAxisRotateEulerDegrees(0.0f, -90.0f, 0.0f);

		std::shared_ptr<myEngine::MeshRenderer> wall_renderer = wall->addComponent<myEngine::MeshRenderer>();
		wall_renderer->setMesh(squareMesh);
		wall_renderer->setShaders("../resources/textured.vert", "../resources/textured.frag");
		wall_renderer->setTexture(wallTex);

		std::shared_ptr<myEngine::Entity> wall2 = core->addEntity();

		std::shared_ptr<myEngine::Transform> wall2_transform = wall2->addComponent<myEngine::Transform>();
		wall2_transform->translate(-35.0f, -1.0f, 10.0f * z);
		wall2_transform->scale(10.0f, 10.0f, 0.0f);
		wall2_transform->localAxisRotateEulerDegrees(0.0f, 90.0f, 0.0f);

		std::shared_ptr<myEngine::MeshRenderer> wall2_renderer = wall2->addComponent<myEngine::MeshRenderer>();
		wall2_renderer->setMesh(squareMesh);
		wall2_renderer->setShaders("../resources/textured.vert", "../resources/textured.frag");
		wall2_renderer->setTexture(wallTex);
	}

	for (int x = -3; x <= 3; x++)
	{
		std::shared_ptr<myEngine::Entity> wall = core->addEntity();

		std::shared_ptr<myEngine::Transform> wall_transform = wall->addComponent<myEngine::Transform>();
		wall_transform->translate(10.0f * x, -1.0f, 35.0f);
		wall_transform->scale(10.0f, 10.0f, 0.0f);
		wall_transform->localAxisRotateEulerDegrees(0.0f, 0.0f, 0.0f);

		std::shared_ptr<myEngine::MeshRenderer> wall_renderer = wall->addComponent<myEngine::MeshRenderer>();
		wall_renderer->setMesh(squareMesh);
		wall_renderer->setShaders("../resources/textured.vert", "../resources/textured.frag");
		wall_renderer->setTexture(wallTex);

		std::shared_ptr<myEngine::Entity> wall2 = core->addEntity();

		std::shared_ptr<myEngine::Transform> wall2_transform = wall2->addComponent<myEngine::Transform>();
		wall2_transform->translate(10.0f * x, -1.0f, -35.0f);
		wall2_transform->scale(10.0f, 10.0f, 0.0f);
		wall2_transform->localAxisRotateEulerDegrees(0.0f, -180.0f, 0.0f);

		std::shared_ptr<myEngine::MeshRenderer> wall2_renderer = wall2->addComponent<myEngine::MeshRenderer>();
		wall2_renderer->setMesh(squareMesh);
		wall2_renderer->setShaders("../resources/textured.vert", "../resources/textured.frag");
		wall2_renderer->setTexture(wallTex);
	}





	//std::shared_ptr<myEngine::BoxCollider> newenemy_collider = newenemy->addComponent<myEngine::BoxCollider>();

	//---------------------------------------create GUI---------------------------------------

	std::shared_ptr<myEngine::Texture> GUITex = std::make_shared<myEngine::Texture>();
	GUITex->loadTexture("../resources/crosshair.png");

	std::shared_ptr<myEngine::Entity> GUIcrosshair = core->addEntity();

	std::shared_ptr<myEngine::GUIRect> GUIcrosshair_GUIRect = GUIcrosshair->addComponent<myEngine::GUIRect>();
	GUIcrosshair_GUIRect->setRect((float)core->getWindowObject()->getWidth() / 2, (float)core->getWindowObject()->getHeight() / 2, 1.0, 1.0);
	GUIcrosshair_GUIRect->setTexture(GUITex);
	GUIcrosshair_GUIRect->setShaders("../resources/GUI.vert", "../resources/textured.frag");

	core->begin();

	return 0;
}
