#include "Transform.h"

namespace myEngine {

	void Transform::onAwake()
	{
		std::cout << "Transform Awake" << std::endl;
	}

	void Transform::onStart()
	{
		std::cout << "Transform Start" << std::endl;
	}

	void Transform::onUpdate()
	{
		std::cout << "Transform Update" << std::endl;
	}

	void Transform::onDisplay()
	{
		std::cout << "Transform Display" << std::endl;
	}

}