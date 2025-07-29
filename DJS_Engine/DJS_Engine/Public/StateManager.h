#pragma once
#include <memory>
#include "GameState.h"

class DJS_ENGINE;

class StateManager {
	friend DJS_ENGINE;
private:
	void Update();
	void Draw();
	void Exit();

	std::unique_ptr<GameState> currState;
	std::unique_ptr<GameState> nextState;
public:
	void SetNextGameState(std::unique_ptr<GameState> nextState);
	GameState* GetCurrGameState() const;
};