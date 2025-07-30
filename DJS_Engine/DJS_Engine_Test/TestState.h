#pragma once

#include "Engine.h"
#include "TestObj.h"

class TestState :public GameState{
public:
	void Init();
	void Draw();

	TestObj Obj;
};