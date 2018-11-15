#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "Component.h"

namespace myEngine
{

	class Move : public Component
	{
	private:

		bool add;
		int i;

	public:

		void start();
		void update();

	};

}