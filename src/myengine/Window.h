#include <SDL2/SDL.h>
#include <memory>

#include "Component.h"

namespace myEngine {

	class Window : public Component
	{

	private:

		void onAwake();
		void onAwake(std::string _name, int _width, int _height);
		void onStart();
		void onUpdate();
		void onDisplay();


		//std::shared_ptr<SDL_Window> window;
		SDL_Window *window;

		std::string name;
		int width;
		int height;

	public:


		static std::shared_ptr<Window> createWindow(std::shared_ptr<Core> _core, std::string _name, int _width, int _height);


	};

}