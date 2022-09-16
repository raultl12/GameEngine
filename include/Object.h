#pragma once

#include "SFMLincludes.h"
#include "ObjectComponent.h"

class Object
{
private:

protected:
	sf::CircleShape circle;

public:
	Object();
	Object(float posX, float posY);
	virtual ~Object();

	virtual void Update(const float* deltaTime);
	virtual void Render(sf::RenderTarget* target);
};

