#ifndef CORE_H
#define CORE_H

#include <memory>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <GL/glew.h>
#include <glm/ext.hpp>

#include "Window.h"
#include "Enviroment.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Sound.h"
#include "RenderTexture.h"
#include "Mesh.h"

namespace myEngine {

	class Camera;
	class Entity;

	/**
	* Gameengine Core
	*	Stores all Entities, WindowObject, SoundObject, Enviroment, Keyboard and Mouse Input
	* Contains main engine loop
	*/
	class Core
	{

	private:
		std::vector<std::shared_ptr<Entity>> m_entities; ///< All entities in the scene
		std::shared_ptr<Window> m_windowObject;
		std::shared_ptr<SoundObject> m_soundObject;
		std::weak_ptr<Core> m_self;

		std::shared_ptr<Camera> m_currentCamera; ///< Camera currently being used for rendering

		std::shared_ptr<Enviroment> m_enviroment;

		std::shared_ptr<Keyboard> m_keyboardInput;
		std::shared_ptr<Mouse> m_mouseInput;

		std::shared_ptr<Texture> m_screenTex;
		std::shared_ptr<Mesh> m_screenRect;
		std::shared_ptr<ShaderProgram> m_screenShader; //will be replaced with a post process

		bool running;

	public:
		static std::shared_ptr<Core> init(); ///< Create Core, Initialise SDL, create SoundObject, Enviroment, KeyboardInput, MouseInput

		Core();
		~Core();

		std::shared_ptr<Window> createNewWindowObject(std::string _name, int _width, int _height); ///< Create new WindowObject, Initialise glew
		std::shared_ptr<Window> getWindowObject() { return m_windowObject; }

		void begin(); ///< Begin the main engine loop

		void update(); ///< Update Enviroment, Mouse and Keyboard Input, Calls all Entity update, physicsUpdate, lateUpdate and Delete all Entities marked for deletion
		void display(); ///< Render scene for each camera

		void GUI(); ///< Calls all Entities GUI

		void debug();

		void end();

		std::shared_ptr<Entity> addEntity(); ///< Creates a new Entity, adds it to the list of Entities
		std::shared_ptr<Entity> addEntity(std::string _name); ///< Creates a new Entity, adds it to the list of Entities, names it _name

		template<typename T> void getComponents(std::vector<std::shared_ptr<T>> *_list) ///< fills _list with all Components of Type T
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

		void setScreenTex(std::shared_ptr<Texture> _texture) { m_screenTex = _texture; }


	};

}

#endif //CORE_H
