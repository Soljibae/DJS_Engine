#include "TestState.h"

void TestState::Init()
{
	DJS_ENGINE::GetInstance().GetEngineContext().renderManager->textureManager.LoadTexture("test", "Assets/test.png");
	DJS_ENGINE::GetInstance().GetEngineContext().renderManager->cameraManager.SetCameraOn(true);

	Obj.Init();
}

void TestState::Update()
{
	DJS_ENGINE::GetInstance().GetEngineContext().renderManager->cameraManager.SetCameraPosition(200.f, 200.f);
}

void TestState::Draw()
{
	Obj.Draw();
}