#pragma once

#include "Object.h"
#include <vector>

class Engine
{
private:
	sf::RenderWindow* window;
	sf::Event event;

	sf::Clock clock;
	float deltaTime;

	std::vector<Object*> objects;
	float spawnCoolDown;

	//Functions
	void SpawnObject();
	void UpdateCoolDown();

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

