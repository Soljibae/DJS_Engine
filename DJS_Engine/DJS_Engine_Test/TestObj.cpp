#include "TestObj.h"

void TestObj::Init()
{
	DJS_ENGINE::GetInstance().GetEngineContext().renderManager->textureManager.LoadTexture("test", "Assets/test.png");
}

void TestObj::Draw()
{
	DJS_ENGINE::GetInstance().GetEngineContext().renderManager->Draw("test", 0.f, 0.f, 200.f, 200.f);
}