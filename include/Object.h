#pragma once

#include "SFMLincludes.h"
#include "ObjectComponent.h"

class Object
{
private:

protected:
	sf::CircleShape circle;
	std::vector<ObjectComponent*> components;

	//Protected Functions
	virtual void UpdateComponents(const float* deltaTime);

public:
	Object();
	Object(float posX, float posY);
	virtual ~Object();

	virtual void Update(const float* deltaTime);
	virtual void Render(sf::RenderTarget* target);
};

