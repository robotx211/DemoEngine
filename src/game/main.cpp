#include <iostream>
#include <memory>

#include <myengine/myengine.h>
#include <game/Move.h>
#include <myengine/GL_Triangle.h>

#include <game/GameController.h>
#include <game/CameraController.h>
#include <game/EnemyController.h>

#include <game/PostProcess_LightKey.h>
#include <game/PostProcess_Blur.h>
#include <game/PostProcess_Bloom.h>

#include <game/PostProcess_B&W.h>
#include <game/PostProcess_Vignette.h>
#include <game/PostProcess_Noise.h>

int main()
{


	std::shared_ptr<myEngine::Core> core = myEngine::Core::init();
	std::shared_ptr<myEngine::Window> window = core->createNewWindowObject("main window", 1280, 720);

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
	drawcamera_controller->setCameraSpeed(1.0f);
	drawcamera_controller->setMovementSpeed(0.1f);

	//---------------------------------------set post process---------------------------------------

	std::shared_ptr<PostProcess_Vignette> vignettePostProcess = std::make_shared< PostProcess_Vignette>(window->getWidth(), window->getHeight());
	std::shared_ptr<PostProcess_BandW> blackAndWhitePostProcess = std::make_shared< PostProcess_BandW>(window->getWidth(), window->getHeight());
	std::shared_ptr<PostProcess_Bloom> bloomPostProcess = std::make_shared< PostProcess_Bloom>(window->getWidth(), window->getHeight());
	std::shared_ptr<PostProcess_Noise> noisePostProcess = std::make_shared< PostProcess_Noise>(window->getWidth(), window->getHeight());


	core->addPostProcess(bloomPostProcess);
	core->addPostProcess(blackAndWhitePostProcess);
	core->addPostProcess(vignettePostProcess);
	core->addPostProcess(noisePostProcess);

	//---------------------------------------create curuthers resources---------------------------------------

	std::vector <std::shared_ptr<myEngine::Mesh>> catMesh;
	myEngine::Mesh::loadModel("../resources/curuthers.obj", &catMesh);

	glm::vec4 catMeshSize = myEngine::Mesh::getVertexPositionRangeFromMeshes(&catMesh);

	glm::vec4 catMeshCentre = myEngine::Mesh::getCentreFromMeshes(&catMesh);

	std::shared_ptr<myEngine::Texture> catTex = std::make_shared<myEngine::Texture>();
	catTex->loadTexture("../resources/curuthers_diffuse.png");

	//---------------------------------------spawn curuthers---------------------------------------

	//std::shared_ptr<myEngine::Entity> newcat = core->addEntity();
	//newcat->setName("cat");

	//std::shared_ptr<myEngine::Transform> newcat_transform = newcat->addComponent<myEngine::Transform>();

	//glm::vec3 requiredSize = glm::vec3(1.0f);

	//newcat_transform->scale(glm::vec3(requiredSize.y / catMeshSize.y));

	//newcat_transform->translate( glm::vec3(catMeshCentre) * glm::vec3(requiredSize.y / catMeshSize.y) * glm::vec3(0.0f, 1.0f, 0.0f) );
	//newcat_transform->translate(-0.5f, 0.0f, 0.0f);

	//std::shared_ptr<myEngine::MeshRenderer> newcat_renderer = newcat->addComponent<myEngine::MeshRenderer>();
	//newcat_renderer->setMesh(&catMesh);
	//newcat_renderer->setShaders("../resources/textured.vert", "../resources/textured.frag");
	//newcat_renderer->setTexture(catTex);

	//newcat->addComponent<Move>();

	//---------------------------------------create cube resources---------------------------------------

	std::vector <std::shared_ptr<myEngine::Mesh>> cubeMesh;
	myEngine::Mesh::loadModel("../resources/cube.obj", &cubeMesh);

	glm::vec4 cubeMeshSize = myEngine::Mesh::getVertexPositionRangeFromMeshes(&cubeMesh);

	std::shared_ptr<myEngine::Texture> cubeTex = std::make_shared<myEngine::Texture>();
	cubeTex->loadTexture("../resources/transparent_bricks.png");

	//---------------------------------------spawn cube---------------------------------------

	std::shared_ptr<myEngine::Entity> cube = core->addEntity();
	cube->setName("cube");

	std::shared_ptr<myEngine::Transform> cube_transform = cube->addComponent<myEngine::Transform>();
	cube_transform->scale(1.0f, 1.0f, 1.0f);
	cube_transform->translate(0.0f, 0.0f, 0.0f);

	std::shared_ptr<myEngine::MeshRenderer> cube_renderer = cube->addComponent<myEngine::MeshRenderer>();
	cube_renderer->setMesh(&cubeMesh);
	cube_renderer->setShaders("../resources/textured_lit.vert", "../resources/textured_lit.frag");
	cube_renderer->setTexture(cubeTex);

	//newcube->addComponent<Move>();

	//---------------------------------------spawn point light source---------------------------------------

	std::shared_ptr<myEngine::Entity> ambientlight = core->addEntity();
	ambientlight->setName("ambient light");

	std::shared_ptr<myEngine::Light> ambientlight_light = ambientlight->addComponent<myEngine::Light>();
	ambientlight_light->setColour(glm::vec3(1.0f, 1.0f, 1.0f));
	ambientlight_light->setStrength(1.0f);

	//---------------------------------------create world---------------------------------------

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

	//floor->addComponent<Move>();

	//---------------------------------------begin---------------------------------------

	core->begin();

	return 0;
}
