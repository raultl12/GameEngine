#include "Object.h"

void Object::UpdateComponents(const float* deltaTime)
{
	if (this->components.size() > 0) {
		for (int i = 0; i < this->components.size(); i++)
		{
			this->components[i]->Update(deltaTime);
		}
	}
}

Object::Object()
{
	this->circle.setFillColor(sf::Color::White);
	this->circle.setRadius(25.f);
	this->circle.setPosition(50.f, 50.f);
}

Object::Object(float posX, float posY)
{
	this->circle.setFillColor(sf::Color::White);
	this->circle.setRadius(25.f);
	this->circle.setPosition(sf::Vector2f(posX, posY));
}

Object::~Object()
{
	if(components.size() > 0){
		for (int i = 0; i < this->components.size(); i++)
		{
			delete this->components[i];
		}
		
	}
}

void Object::Update(const float* deltaTime)
{
	this->UpdateComponents(deltaTime);
}

void Object::Render(sf::RenderTarget* target)
{
	target->draw(this->circle);
}
