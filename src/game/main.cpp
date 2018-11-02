#include <iostream>
#include <memory>

#include <myengine/myengine.h>

int main()
{

  //std::shared_ptr<myEngine::Core> core = myEngine::Core::init();
  //core->createNewWindowObject("main window", 1280, 720);

  //std::shared_ptr<myEngine::Entity> entity = core->addEntity("Triangle");

  //std::shared_ptr<myEngine::GL_Triangle> triangle = entity->addComponent<myEngine::GL_Triangle>();

  //core->begin();



  std::shared_ptr<myEngine::Mesh> mesh = std::make_shared<myEngine::Mesh>();

  mesh->loadModel("../resources/cube.obj");


  //std::cout << "Split String By Char Test" << std::endl;

  //std::string input = "Hello//There/My//Fellow/Children//*holds skateboard*";

  //std::vector<std::string> output;

  //myEngine::splitStringByChar(input, '/', output);

  //std::cout << "Input: " << input << std::endl << std::endl;

  //std::cout << "Output: ";
  //for (int i = 0; i < output.size(); i++)
  //{
  //  std::cout << output.at(i);
  //}
  //std::cout << std::endl << std::endl;

  std::cin.get();

  return 0;
}
