#include <SDL2/SDL.h>
#include <memory>

namespace myEngine {

	class Window
	{

	private:

		void update();


		//std::shared_ptr<SDL_Window> window;
		SDL_Window *window;

		std::string name;
		int width;
		int height;

	public:

		void init(std::string _name, int _width, int _height);

	};

}