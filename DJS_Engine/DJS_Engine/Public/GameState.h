#pragma once

#include "GameObject.h"
#include "StateManager.h"
#include "ObjectManager.h"

class GameState {
	friend StateManager;
public:
	virtual ~GameState() = default;
protected:
	virtual void Init() {}
	virtual void LateInit() {}
	virtual void Update() {}
	virtual void LateUpdate() {} //for collsion
	virtual void Draw() {}
	virtual	void Exit() {}

	ObjectManager objectmanager;
private:
	void StateInit()
	{
		Init();
		objectmanager.InitAll();
		LateInit();
	}
	void StateUpdate()
	{
		Update();
		objectmanager.UpdateAll();
		LateUpdate();
	}
	void StateExit()
	{
		Exit();
		objectmanager.ExitAll();
	}

};
