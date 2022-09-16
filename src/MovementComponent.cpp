#include "MovementComponent.h"

//Constructors
MovementComponent::MovementComponent(){
    this->transform.position.x = 0;
    this->transform.position.y = 0;
    this->moving = false;
}

MovementComponent::MovementComponent(Transform* transform){
    this->transform.position.x = transform->position.x;
    this->transform.position.y = transform->position.y;
    this->moving = false;
}

//Destructor
MovementComponent::~MovementComponent(){

}

//Functions
void MovementComponent::Move(Transform* transform){
    this->transform.position.x = transform->position.x;
    this->transform.position.y = transform->position.y;
}

void MovementComponent::Update(const float* deltaTime, Transform* transform){
    if(this->moving){
        this->Move(transform);
    }
}

//void MovementComponent::Render(sf::RenderTarget* target){}
