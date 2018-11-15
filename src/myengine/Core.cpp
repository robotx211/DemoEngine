#include "Core.h"
#include "Entity.h"
#include "Component.h"
#include "Camera.h"

namespace myEngine {

  std::shared_ptr<Core> Core::init()
  {
    std::shared_ptr<Core> newCore = std::make_shared<Core>();
    newCore->m_self = newCore;

    newCore->running = false;

		return newCore;
  }

	Core::Core()
	{

	}
	Core::~Core()
	{

	}

  std::shared_ptr<Window> Core::createNewWindowObject(std::string _name, int _width, int _height)
  {
    std::shared_ptr<Window> newWindowObject = std::make_shared<Window>(_name, _width, _height);

    m_windowObject = newWindowObject;

		//create SDL GL Context
		if (!SDL_GL_CreateContext(m_windowObject->getWindow()))
		{
			std::cout << "GLContext is null" << std::endl;
			throw std::exception();
		}

		//init glew
		if (glewInit() != GLEW_OK)
		{
			std::cout << "glewInit failed" << std::endl;
			throw std::exception();
		}

    return m_windowObject;

  }


  void Core::begin()
  {
    running = true;


    while (running == true)
    {

      update();

      display();


    }

  }

  void Core::update()
  {
    for (size_t i = 0; i < m_entities.size(); i++)
    {
      m_entities.at(i)->update();
    }
  }

  void Core::display()
  {
    //set clear colour of _window
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

		std::vector<std::shared_ptr<Camera>> *camList = new std::vector<std::shared_ptr<Camera>>();
		getComponents<Camera>(camList);

		if (camList->size() == 0)
		{
			throw std::exception();
		}
		else
		{
			for (size_t i = 0; i < camList->size(); i++)
			{
				setCurrentCamera(camList->at(i));
				for (size_t j = 0; j < m_entities.size(); j++)
				{
					m_entities.at(j)->display();
				}
			}
		}

    SDL_GL_SwapWindow(m_windowObject->getWindow());
  }

  void Core::debug()
  {
    std::cout << "Entities: " << m_entities.size() << std::endl;

    for (size_t i = 0; i < m_entities.size(); i++)
    {
      m_entities.at(i)->debug();
    }
  }

  void Core::end()
  {
    running = false;
  }

	std::shared_ptr<Entity> Core::addEntity()
	{
		std::shared_ptr<Entity> newEntity = std::make_shared<Entity>();

		newEntity->m_self = newEntity;
		newEntity->m_core = m_self;

		m_entities.push_back(newEntity);

		return newEntity;
	}

  std::shared_ptr<Entity> Core::addEntity(std::string _name)
  {
    std::shared_ptr<Entity> newEntity = std::make_shared<Entity>(_name);

    newEntity->m_self = newEntity;
    newEntity->m_core = m_self;

    m_entities.push_back(newEntity);

    return newEntity;
  }

	void Core::setCurrentCamera(std::shared_ptr<Camera> _cam)
	{
		m_currentCamera = _cam;
	}
	std::shared_ptr<Camera> Core::getcurrentCamera()
	{
		return m_currentCamera;
	}

}

