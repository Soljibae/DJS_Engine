#include "Engine.h"

int main()
{
    DJS_ENGINE::GetInstance().Init();

    //DJS_ENGINE::GetInstance().GetEngineContext().windowManager->SetWindowTitle("New title");

    DJS_ENGINE::GetInstance().Run();

    DJS_ENGINE::GetInstance().Exit();

    return 0;
}