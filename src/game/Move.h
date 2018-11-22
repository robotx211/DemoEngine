#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include <myengine/myengine.h>

	class Move : public myEngine::Component
	{
	private:

		bool add;
		int i;

	public:

		void start();
		void update();

	};