#pragma once

#include "Object.h"
#include "MovementComponent.h"

class OCharacter : public Object{
protected:
    MovementComponent* movementComponent;
    Transform transform;

public:
    OCharacter();
    OCharacter(float posX, float posY);

    //Functions
    void Update(const float* deltaTime);
    void Render(const sf::RenderTarget* target);
};