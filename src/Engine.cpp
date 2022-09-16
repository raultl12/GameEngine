#include "Engine.h"

//Private Functions
void Engine::SpawnObject()
{
	if (this->inputCoolDown == 0.f) {
		this->inputCoolDown = COOLDOWNTIME;
		this->objects.push_back(new Object(sf::Mouse::getPosition(*this->window).x,
			sf::Mouse::getPosition(*this->window).y));
	}
}

void Engine::UpdateCoolDown()
{
	if (this->inputCoolDown > 0) {
		this->inputCoolDown--;
	}
	else {
		inputCoolDown = 0.f;
	}
}

bool Engine::CheckForKeyPressed(){
	bool keyPressed = false;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
			keyPressed = true;
	}
	

	return keyPressed;
}

void Engine::ManageKeys(){
	if(this->inputCoolDown == 0.f){
		this->inputCoolDown = COOLDOWNTIME;
		std::cout << "Key pressed\n";
	}
}

//Constructor
Engine::Engine()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Engine");
	this->inputCoolDown = 0.f;

}

//Destructor
Engine::~Engine()
{
	delete this->window;
	for (int i = 0; i < this->objects.size(); i++)
	{
		delete this->objects[i];
	}
}

//Functions

void Engine::updateDeltaTime()
{
	this->deltaTime = this->clock.restart().asSeconds();
}

void Engine::UpdateSFMLEvents()
{
	while (this->window->pollEvent(this->event)) {

		if (event.type == sf::Event::Closed) {
			this->window->close();
		}

		if (!this->CheckForKeyPressed() && event.mouseButton.button == sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			this->SpawnObject();
		}

		if(this->CheckForKeyPressed()){
			this->ManageKeys();
		}
	}
}

void Engine::UpdateObjects(){
	if(this->objects.size() > 0){
		for (int i = 0; i < this->objects.size(); i++)
		{
			this->objects[i]->Update(&this->deltaTime);
		}
		
	}
}

void Engine::Run()
{
	while (this->window->isOpen()) {
		this->Update(this->deltaTime);
		this->Render();
	}
}

void Engine::Update(const float& deltaTime)
{
	this->updateDeltaTime();
	this->UpdateSFMLEvents();
	this->UpdateCoolDown();
	this->UpdateObjects();

	//std::cout << this->deltaTime << "\n";
	//std::cout << this->objects.size() << "\n";
}

void Engine::Render()
{
	this->window->clear();

	//Render things
	if (this->objects.size() > 0) {
		for (int i = 0; i < this->objects.size(); i++)
		{
			this->objects[i]->Render(this->window);
		}
	}

	this->window->display();
}
