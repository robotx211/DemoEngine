#include "Component.h"

namespace myengine
{

	class Camera::public Component
	{

		virtual void awake();
		virtual void start();
		virtual void update();
		virtual void display();

		virtual void debug();

	};

}