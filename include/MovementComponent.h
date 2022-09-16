#pragma once

#include "ObjectComponent.h"
#include "Transform.h"

class MovementComponent : public ObjectComponent{
protected:
    Transform transform;

    bool moving;
public:
    MovementComponent();
    MovementComponent(Transform* transform);
    ~MovementComponent();

    //Functions
    void Move(Transform* transform);
    void Update(const float* deltaTime, Transform* transform);
    //void Render(sf::RenderTarget* target);


};