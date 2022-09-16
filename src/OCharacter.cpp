#include "OCharacter.h"

//Constructor
OCharacter::OCharacter(){
    this->movementComponent = new MovementComponent(&this->transform);
}

OCharacter::OCharacter(float posX, float posY){
    //Object(posX, posY);
    this->circle.setPosition(sf::Vector2f(posX, posY));
    this->transform.position.x = posX;
    this->transform.position.y = posY;
    this->movementComponent = new MovementComponent(&this->transform);
}

//Destructor
//Functions

void OCharacter::Update(const float* deltaTime){
    
    this->movementComponent->Update(deltaTime);
    this->transform = this->movementComponent->GetTransform();
    this->circle.setPosition(this->transform.position.x, this->transform.position.y);

}
