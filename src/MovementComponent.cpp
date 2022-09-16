#include "MovementComponent.h"

//Constructors
MovementComponent::MovementComponent(){
    this->transform.position.x = 0;
    this->transform.position.y = 0;
    this->moving = false;
    this->speed = 500.f;
}

MovementComponent::MovementComponent(Transform* transform){
    this->transform.position.x = transform->position.x;
    this->transform.position.y = transform->position.y;
    this->moving = false;
    this->speed = 500.f;
}

//Destructor
MovementComponent::~MovementComponent(){

}

//Functions

void MovementComponent::Update(const float* deltaTime){

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        this->transform.position.x += -1 * this->speed * *deltaTime;
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        this->transform.position.y += -1 * this->speed * *deltaTime;
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        this->transform.position.x += 1 * this->speed * *deltaTime;
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        this->transform.position.y += 1 * this->speed * *deltaTime;
    }
}