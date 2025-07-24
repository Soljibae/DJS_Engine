#pragma once
#include "GameObject.h"
#include <vector>
#include <memory>

class GameState;

class ObjectManager {
	friend GameState;
private:
	std::vector<std::unique_ptr<GameObject>> objects;

	void InitAll();
	void UpdateAll();
	void ExitAll();
public:
	void AddObjectToList(std::unique_ptr<GameObject> object);
};