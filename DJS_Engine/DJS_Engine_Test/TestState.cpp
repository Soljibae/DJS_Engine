#include "TestState.h"

void TestState::Init()
{
	DJS_ENGINE::GetInstance().GetEngineContext().renderManager->textureManager.LoadTexture("test", "Assets/test.png");

	Obj.Init();
}

void TestState::Draw()
{
	Obj.Draw();
}