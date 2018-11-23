#ifndef CORE_H
#define CORE_H

#include <memory>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <GL/glew.h>

#include "Window.h"
#include "Enviroment.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Sound.h"

namespace myEngine {

	class Camera;
	class Entity;

	class Core
	{

	private:
		std::vector<std::shared_ptr<Entity>> m_entities;
		std::shared_ptr<Window> m_windowObject;
		std::shared_ptr<SoundObject> m_soundObject;
		std::weak_ptr<Core> m_self;

		std::shared_ptr<Camera> m_currentCamera;

		std::shared_ptr<Enviroment> m_enviroment;

		std::shared_ptr<Keyboard> m_keyboardInput;
		std::shared_ptr<Mouse> m_mouseInput;

		bool running;

	public:
		static std::shared_ptr<Core> init();

		Core();
		~Core();

		std::shared_ptr<Window> createNewWindowObject(std::string _name, int _width, int _height);
		std::shared_ptr<Window> getWindowObject() { return m_windowObject; }


		void begin();

		void update();
		void display();

		void debug();

		void end();

		std::shared_ptr<Entity> addEntity();
		std::shared_ptr<Entity> addEntity(std::string _name);

		template<typename T> void getComponents(std::vector<std::shared_ptr<T>> *_list)
		{
			for (size_t i = 0; i < m_entities.size(); i++)
			{
				try
				{
					_list->push_back(m_entities.at(i)->getComponent<T>());
				}
				catch (...)
				{
					//no component type
				}
			}
		}

		void setCurrentCamera(std::shared_ptr<Camera> _cam);
		std::shared_ptr<Camera> getCurrentCamera();

		std::shared_ptr<Enviroment> getEnviroment() { return m_enviroment; }

		std::shared_ptr<Keyboard> getKeyboard() { return m_keyboardInput; }
		std::shared_ptr<Mouse> getMouse() { return m_mouseInput; }


	};

}

#endif //CORE_H
