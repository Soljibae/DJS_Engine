#include "TestObj.h"

void TestObj::Init()
{
}

void TestObj::Draw()
{
	DJS_ENGINE::GetInstance().GetEngineContext().renderManager->Draw("test", 0.f, 0.f, 200.f, 200.f);
}