#include <iostream>
#include <memory>

#include <myengine/myengine.h>
#include <game/Move.h>
#include <myengine/GL_Triangle.h>

#include <game/GameController.h>
#include <game/CameraController.h>
#include <game/EnemyController.h>

#include <game/PostProcess_Blur.h>

int main()
{


	std::shared_ptr<myEngine::Core> core = myEngine::Core::init();
	std::shared_ptr<myEngine::Window> window = core->createNewWindowObject("main window", 1280, 720);

	//---------------------------------------TinyOBJ Loader testing---------------------------------------

	//std::vector<std::shared_ptr<myEngine::Mesh>> meshes;

	//myEngine::Mesh::loadModel("../resources/cube.obj", &meshes);

	//return 0;

	//---------------------------------------create draw camera---------------------------------------

	std::shared_ptr<myEngine::Entity> drawcamera = core->addEntity();
	drawcamera->setName("draw cam");

	std::shared_ptr<myEngine::Transform> drawcamera_transform = drawcamera->addComponent<myEngine::Transform>();

	drawcamera_transform->translate(0.0f, 0.0f, 10.0f);

	std::shared_ptr<myEngine::Camera> drawcamera_camera = drawcamera->addComponent<myEngine::Camera>();

	drawcamera_camera->setDegFOV(45.0f);
	drawcamera_camera->setAspectRatio(core->getWindowObject()->getAspectRatio());

	std::shared_ptr<myEngine::RenderTexture> screen_rendertexture = std::make_shared<myEngine::RenderTexture>();

	screen_rendertexture->setSize(window->getWidth(), window->getHeight());
	screen_rendertexture->init();

	drawcamera_camera->setRenderTexture(screen_rendertexture);

	core->setScreenTex(screen_rendertexture);

	std::shared_ptr<CameraController> drawcamera_controller = drawcamera->addComponent<CameraController>();
	drawcamera_controller->setCameraSpeed(0.01f);
	drawcamera_controller->setMovementSpeed(0.1f);

	//---------------------------------------set post process---------------------------------------

	std::shared_ptr<PostProcess_Blur> blurPostProcess = std::make_shared< PostProcess_Blur>(window->getWidth(), window->getHeight());

	core->setPostProcess(blurPostProcess);

	//---------------------------------------create curuthers resources---------------------------------------

	std::vector <std::shared_ptr<myEngine::Mesh>> catMesh;
	myEngine::Mesh::loadModel("../resources/curuthers.obj", &catMesh);

	glm::vec4 catMeshSize = myEngine::Mesh::getVertexPositionRangeFromMeshes(&catMesh);

	glm::vec4 catMeshCentre = myEngine::Mesh::getCentreFromMeshes(&catMesh);

	std::shared_ptr<myEngine::Texture> catTex = std::make_shared<myEngine::Texture>();
	catTex->loadTexture("../resources/curuthers_diffuse.png");

	//---------------------------------------spawn curuthers---------------------------------------

	std::shared_ptr<myEngine::Entity> newcat = core->addEntity();
	newcat->setName("cat");

	std::shared_ptr<myEngine::Transform> newcat_transform = newcat->addComponent<myEngine::Transform>();

	glm::vec3 requiredSize = glm::vec3(1.0f);

	newcat_transform->scale(glm::vec3(requiredSize.y / catMeshSize.y));

	newcat_transform->translate( glm::vec3(catMeshCentre) * glm::vec3(requiredSize.y / catMeshSize.y) * glm::vec3(0.0f, 1.0f, 0.0f) );
	newcat_transform->translate(-0.5f, 0.0f, 0.0f);

	std::shared_ptr<myEngine::MeshRenderer> newcat_renderer = newcat->addComponent<myEngine::MeshRenderer>();
	newcat_renderer->setMesh(&catMesh);
	newcat_renderer->setShaders("../resources/textured.vert", "../resources/textured.frag");
	newcat_renderer->setTexture(catTex);

	//---------------------------------------create cube resources---------------------------------------

	std::vector <std::shared_ptr<myEngine::Mesh>> cubeMesh;
	myEngine::Mesh::loadModel("../resources/cube.obj", &cubeMesh);

	glm::vec4 cubeMeshSize = myEngine::Mesh::getVertexPositionRangeFromMeshes(&cubeMesh);

	std::shared_ptr<myEngine::Texture> cubeTex = std::make_shared<myEngine::Texture>();
	cubeTex->loadTexture("../resources/transparent_bricks.png");

	//---------------------------------------spawn cube---------------------------------------

	std::shared_ptr<myEngine::Entity> newcube = core->addEntity();
	newcube->setName("enemy");

	std::shared_ptr<myEngine::Transform> newcube_transform = newcube->addComponent<myEngine::Transform>();
	newcube_transform->scale(1.0f, 1.0f, 1.0f);
	newcube_transform->translate(0.5f, 0.0f, 0.0f);

	std::shared_ptr<myEngine::MeshRenderer> newcube_renderer = newcube->addComponent<myEngine::MeshRenderer>();
	newcube_renderer->setMesh(&cubeMesh);
	newcube_renderer->setShaders("../resources/textured.vert", "../resources/textured.frag");
	newcube_renderer->setTexture(cubeTex);



	//---------------------------------------create world---------------------------------------

	//std::shared_ptr<myEngine::Mesh> squareMesh = std::make_shared<myEngine::Mesh>();
	//squareMesh->loadModel("../resources/square.obj");
	std::vector <std::shared_ptr<myEngine::Mesh>> squareMesh;
	myEngine::Mesh::loadModel("../resources/square.obj", &squareMesh);

	std::shared_ptr<myEngine::Texture> floorTex = std::make_shared<myEngine::Texture>();
	floorTex->loadTexture("../resources/floor.png");

	std::shared_ptr<myEngine::Entity> floor = core->addEntity();

	std::shared_ptr<myEngine::Transform> floor_transform = floor->addComponent<myEngine::Transform>();
	floor_transform->translate(0.0f, 1.0f, 0.0f);
	floor_transform->scale(10.0f, 10.0f, 0.0f);
	floor_transform->localAxisRotateEulerDegrees(90.0f, 0.0f, 0.0f);

	std::shared_ptr<myEngine::MeshRenderer> floor_renderer = floor->addComponent<myEngine::MeshRenderer>();
	floor_renderer->setMesh(squareMesh.at(0));
	floor_renderer->setShaders("../resources/textured.vert", "../resources/textured.frag");
	floor_renderer->setTexture(floorTex);

	//---------------------------------------begin---------------------------------------

	core->begin();

	return 0;
}
