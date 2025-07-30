#include "Engine.h"
#include "TestState.h"
#include <memory>

int main()
{
    DJS_ENGINE::GetInstance().Init();

    //DJS_ENGINE::GetInstance().GetEngineContext().windowManager->SetWindowTitle("New title");

    //DJS_ENGINE::GetInstance().GetEngineContext().windowManager->SetCursorHidden(true);

    DJS_ENGINE::GetInstance().GetEngineContext().stateManager->SetNextGameState(std::make_unique<TestState>());

    DJS_ENGINE::GetInstance().Run();

    DJS_ENGINE::GetInstance().Exit();

    return 0;
}