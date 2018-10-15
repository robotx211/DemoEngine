#include <SDL2/SDL.h>
#include <memory>

#include "Component.h"

class Window : public Component
{

private:

public:
	std::string name;
	int width;
	int height;

	SDL_Window *window;

	void init(std::string _name, int _width, int _height);

};