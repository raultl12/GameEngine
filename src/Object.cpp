#include "Object.h"
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

}

void Object::Update(const float* deltaTime){}

void Object::Render(sf::RenderTarget* target)
{
	target->draw(this->circle);
}
