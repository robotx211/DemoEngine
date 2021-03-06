#ifndef CAMERA_H
#define CAMERA_H


#include <memory>
#include <vector>

#include <glm/glm.hpp>

#include "Component.h"
#include "RenderTexture.h"

namespace myEngine
{

	class Camera : public Component
	{
	private:
		
		float m_DegFOV;
		float m_aspectRatio;
		std::shared_ptr<RenderTexture> m_renderTex;

	public:

		Camera();
		~Camera();

		void setDegFOV(float _value); //in degrees

		void setAspectRatio(float _aspect);
		void setAspectRatio(float _width, float _height);
		void setAspectRatioToWindowSize();

		glm::mat4 getViewMatrix();
		float getRadFOV();
		float getAspectRatio();

		void setRenderTexture(std::shared_ptr<RenderTexture> _renderTex);
		bool isRenderTexCamera() { return m_renderTex != nullptr; };
		void bindRenderTexFramebuffer();

		void debug();
	};

}

#endif // !CAMERA_H