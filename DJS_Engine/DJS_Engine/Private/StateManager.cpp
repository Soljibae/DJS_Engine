#include "StateManager.h"
#include "DJS_ENGINE.h"

void StateManager::Update()
{
	if (nextState)
	{
		if (currState)
		{
			currState->Exit();
		}
		currState = std::move(nextState);
		currState->StateInit();
	}
	else
	{
		currState->StateUpdate();
	}
}

void StateManager::Draw()
{
	currState->Draw();
}

void StateManager::Exit()
{
	currState->StateExit();
}

void StateManager::SetNextGameState(std::unique_ptr<GameState> nextState)
{
	this->nextState = std::move(nextState);
}

GameState* StateManager::GetCurrGameState() const
{
	return currState.get();
}