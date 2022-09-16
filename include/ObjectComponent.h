#pragma once

#include "SFMLincludes.h"
#include <iostream>

class ObjectComponent
{
private:

protected:


public:
	ObjectComponent();
	virtual ~ObjectComponent();

	//Functions
	virtual void Update(const float* deltaTime);
	//virtual void Render(sf::RenderTarget* target);

};

