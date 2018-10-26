#include <iostream>
#include <memory>

#include <myengine/myengine.h>

int main()
{

  std::cout << "Start splitStringByWhitespace Test" << std::endl;

  //std::shared_ptr<myEngine::Core> core = myEngine::Core::init();
  //core->createNewWindowObject("main window", 1280, 720);

  //std::shared_ptr<myEngine::Entity> entity = core->addEntity("Triangle");

  //std::shared_ptr<myEngine::GL_Triangle> triangle = entity->addComponent<myEngine::GL_Triangle>();

  //core->begin();

  std::string input =
    "This text is pretty long, but will be "
    "concatenated into just a single string. "
    "The disadvantage is that you have to quote "
    "each part, and newlines must be literal as "
    "usual.";

  std::vector<std::string> output;

  std::cout << "Input:\t" << input << std::endl;
  std::cout << std::endl;

  myEngine::splitStringByWhitespace(input, output);
  
  std::cout << std::endl;
  std::cout << "Output:\t";

  for (size_t i = 0; i < output.size(); i++)
  {
    std::cout << output.at(i);
  }

  std::cout << std::endl;

  std::cin.get();

  return 0;
}
