#pragma once

#include "ObjectComponent.h"
#include "Transform.h"

class MovementComponent : public ObjectComponent{
protected:
    Transform transform;
    float speed;

    bool moving;
public:
    MovementComponent();
    MovementComponent(Transform* transform);
    ~MovementComponent();

    //Functions
    Transform GetTransform(){return transform;}
    void Update(const float* deltaTime);
    //void Render(sf::RenderTarget* target);


};