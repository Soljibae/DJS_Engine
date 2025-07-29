#pragma once

#include "GameObject.h"
#include "ObjectManager.h"

class GameState {
public:
	virtual ~GameState() = default;

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
	virtual void Init() {}
	virtual void LateInit() {}
	virtual void Update() {}
	virtual void LateUpdate() {} //for collsion
	virtual void Draw() {}
	virtual	void Exit() {}

	ObjectManager objectmanager;
protected:

private:
};
