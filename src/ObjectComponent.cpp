#include "ObjectComponent.h"

ObjectComponent::ObjectComponent()
{
}

ObjectComponent::~ObjectComponent()
{
}

void ObjectComponent::Update(const float* deltaTime)
{
	std::cout << "Actualizando componente" << std::endl;
}

void ObjectComponent::Render(sf::RenderTarget* target)
{
}
