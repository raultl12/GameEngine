#pragma once

#include "Object.h"
#include "OCharacter.h"
#include <vector>

const float COOLDOWNTIME = 40.F;

class Engine
{
private:
	sf::RenderWindow* window;
	sf::Event event;

	sf::Clock clock;
	float deltaTime;

	std::vector<Object*> objects;
	float inputCoolDown;

	//Functions
	void SpawnObject();
	void UpdateCoolDown();
	bool CheckForKeyPressed();
	void ManageKeys();

public:
	Engine();
	~Engine();

	//Functions
	void updateDeltaTime();
	void UpdateSFMLEvents();
	void UpdateObjects();
	void Run();
	void Update(const float& deltaTime);
	void Render();
};

