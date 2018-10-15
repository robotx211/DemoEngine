#include "Core.h"
#include "Entity.h"
#include "Window.h"

namespace myEngine {

	void Window::onAwake()
	{
		std::cout << "Window Awake" << std::endl;
	}

	void Window::onAwake(std::string _name, int _width, int _height)
	{
		name = _name;
		width = _width;
		height = _height;

		//window = std::make_shared<SDL_Window>(
		//	SDL_CreateWindow(name.c_str(),
		//		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		//		width, height,
		//		SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL)
		//	);

		window = SDL_CreateWindow(name.c_str(),
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			width, height,
			SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

		std::cout << "Window Awake" << std::endl;
	}

	void Window::onStart()
	{
		std::cout << "Window Start" << std::endl;
	}

	void Window::onUpdate()
	{
		std::cout << "Window Update" << std::endl;
	}

	void Window::onDisplay()
	{
		std::cout << "Window Display" << std::endl;
	}

	std::shared_ptr<Window> Window::createWindow(std::shared_ptr<Core> _core, std::string _name, int _width, int _height)
	{
		std::shared_ptr<myEngine::Entity> newWindowEntity = _core->addEntity();

		std::shared_ptr<myEngine::Window> newWindowComponent = newWindowEntity->addComponent<myEngine::Window>();
	
		return newWindowComponent;
	}

}
