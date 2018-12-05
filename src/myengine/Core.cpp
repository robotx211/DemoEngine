#include "Core.h"
#include "Entity.h"
#include "Component.h"
#include "Camera.h"

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

		glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		
		std::vector<std::shared_ptr<Camera>> *camList = new std::vector<std::shared_ptr<Camera>>();
		getComponents<Camera>(camList);

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

		glDisable(GL_BLEND);

		//if (m_screenTex != nullptr)
		//{
		//	if (m_screenRect == nullptr)
		//	{
		//		m_screenRect = std::make_shared<Mesh>();
		//		m_screenRect->loadRect();
		//	}
		//	if (m_screenShader == nullptr)
		//	{
		//		m_screenShader = std::make_shared<ShaderProgram>("../resources/textured.vert", "../resources/textured.frag");
		//	}

		//	glBindFramebuffer(GL_FRAMEBUFFER, 0);
		//	glViewport(0, 0, m_windowObject->getWidth(), m_windowObject->getHeight());

		//	glm::vec3 translateVec = glm::vec3(m_screenTex->getSize(), 1.0f) * glm::vec3((float)1 / (float)(getWindowObject()->getWidth()) * 100.0f, (float)1 / (float)(getWindowObject()->getHeight()) * 100.0f, 0.0f);
		//	glm::mat4 modelMat = glm::scale(glm::mat4(1.0f), translateVec);

		//	glUseProgram(m_screenShader->getId());

		//	glBindVertexArray(m_screenRect->getModelVAO()->getId());

		//	m_screenTex->bindTexture();

		//	glDrawArrays(GL_TRIANGLES, 0, m_screenRect->getVertexcount());

		//	glBindTexture(GL_TEXTURE_2D, 0);
		//	glBindVertexArray(0);
		//	glUseProgram(0);

		//}

		GUI();

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

}

