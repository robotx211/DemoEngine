#include "Core.h"
#include "Entity.h"
#include "Component.h"
#include "Camera.h"
#include "Light.h"

namespace myEngine {

	std::shared_ptr<Core> Core::init()
	{
		std::shared_ptr<Core> newCore = std::make_shared<Core>();
		newCore->m_self = newCore;

		if (SDL_Init(SDL_INIT_VIDEO) == -1)
		{
			throw std::exception();
		}

		newCore->m_soundObject = std::make_shared<SoundObject>();

		newCore->m_enviroment = std::make_shared<Enviroment>();

		newCore->m_keyboardInput = std::make_shared<Keyboard>();
		newCore->m_mouseInput = std::make_shared<Mouse>(newCore);

		newCore->running = false;

		newCore->m_postProcessIndex = 0;
		newCore->m_lightingIndex = 0;

		return newCore;
	}

	Core::Core()
	{

	}
	Core::~Core()
	{
		SDL_Quit();
	}

	std::shared_ptr<Window> Core::createNewWindowObject(std::string _name, int _width, int _height)
	{
		m_windowObject = std::make_shared<Window>(_name, _width, _height);

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

		glEnable(GL_CULL_FACE);
		glEnable(GL_DEPTH_TEST);

		m_usePostProcess = false;
		m_postProcessIndex = 0;

		while (running == true)
		{

			update();

			//if ESC pressed, quit
			if (getKeyboard()->getKey(SDL_SCANCODE_ESCAPE))
			{
				running = false;
				break;
			}

			display();


		}

	}

	void Core::update()
	{
		m_enviroment->update();

		m_mouseInput->update();
		m_keyboardInput->update();

		for (size_t i = 0; i < m_entities.size(); i++)
		{
			m_entities.at(i)->update();
		}
		for (size_t i = 0; i < m_entities.size(); i++)
		{
			m_entities.at(i)->physicsUpdate();
		}
		for (size_t i = 0; i < m_entities.size(); i++)
		{
			m_entities.at(i)->lateUpdate();
		}


		for (int i = m_entities.size() - 1; i >= 0; i--)
		{
			if (m_entities.at(i)->m_delete == true)
			{
				m_entities.erase(m_entities.begin() + i);
			}
		}

	}

	void Core::display()
	{
		glEnable(GL_DEPTH_TEST);

		glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		
		std::vector<std::shared_ptr<Camera>> *camList = new std::vector<std::shared_ptr<Camera>>();
		getComponents<Camera>(camList);

		std::vector<std::shared_ptr<Light>> *lightList = new std::vector<std::shared_ptr<Light>>();
		getComponents<Light>(&m_lightsList);

		if (camList->size() == 0)
		{
			throw std::exception();
		}
		else
		{
			//draw scene for each camera, if it has a render texture attached, bind it
			for (size_t i = 0; i < camList->size(); i++)
			{

				setCurrentCamera(camList->at(i));

				m_currentCamera->bindRenderTexFramebuffer();

				for (size_t j = 0; j < m_entities.size(); j++)
				{
					m_entities.at(j)->display();
				}

				//unbind fbo
				glBindFramebuffer(GL_FRAMEBUFFER, 0);
				glViewport(0, 0, m_windowObject->getWidth(), m_windowObject->getHeight());
			}
		}

		//Post Process Application

		if (m_screenTex != nullptr)
		{

			//Applys the chosen post process(es)
			if (m_usePostProcess) 
			{
				if (m_postProcessIndex == m_postProcesses.size())
				{
					//Applys the necessary post processes to produce the final image
					for (size_t i = 2; i < m_postProcesses.size(); i++)
					{
						m_postProcesses.at(i)->apply(m_screenTex);
					}
				}
				else
				{
					//Applys a single, selected post process
					m_postProcesses.at(m_postProcessIndex)->apply(m_screenTex);
				}


			}

			glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			if (m_screenRect == nullptr)
			{
				m_screenRect = std::make_shared<Mesh>();
				m_screenRect->loadRect();
			}
			if (m_screenShader == nullptr)
			{
				m_screenShader = std::make_shared<ShaderProgram>("../resources/nullpass.vert", "../resources/nullpass.frag");
			}

			glUseProgram(m_screenShader->getId());

			m_screenShader->setUniform("in_Texture", 0);

			glBindFramebuffer(GL_FRAMEBUFFER, 0);
			glViewport(0, 0, m_windowObject->getWidth(), m_windowObject->getHeight());

			glBindVertexArray(m_screenRect->getModelVAO()->getId());

			m_screenTex->bindTexture();

			glDrawArrays(GL_TRIANGLES, 0, m_screenRect->getVertexcount());

			glBindTexture(GL_TEXTURE_2D, 0);
			glBindVertexArray(0);
			glUseProgram(0);

		}

		glDisable(GL_BLEND);

		//GUI();

		SDL_GL_SwapWindow(m_windowObject->getWindow());
	}

	void Core::GUI()
	{
		for (size_t i = 0; i < m_entities.size(); i++)
		{
			m_entities.at(i)->GUI();
		}
	}

	void Core::debug()
	{
		//std::cout << "Entities: " << m_entities.size() << std::endl;

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
	std::shared_ptr<Camera> Core::getCurrentCamera()
	{
		return m_currentCamera;
	}

	std::vector<std::shared_ptr<Light>> Core::getCurrentLights()
	{

		return m_lightsList;

	}

}

