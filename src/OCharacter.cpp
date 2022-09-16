#include "OCharacter.h"

//Constructor
OCharacter::OCharacter(){
    this->components.push_back(new MovementComponent());
}

OCharacter::OCharacter(float posx, float posY){
    this->components.push_back(new MovementComponent());
}
//Destructor
OCharacter::~OCharacter(){
}
//Functions