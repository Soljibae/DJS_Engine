#pragma once
#include "WindowManager.h"
#include "InputManager.h"
#include "StateManager.h"

struct EngineContext {
	WindowManager* windowManager = nullptr;
	InputManager* inputManager = nullptr;
	StateManager* stateManager = nullptr;
};

class DJS_ENGINE {
private:
	DJS_ENGINE(){}

	~DJS_ENGINE() {}

	bool shouldRun = true;

	void SetEngineContext();

	EngineContext engineContext;
	WindowManager windowManager;
	InputManager inputManager;
	StateManager stateManager;
public:
	static DJS_ENGINE& GetInstance()
	{
		static DJS_ENGINE instance;
		return instance;
	}

	DJS_ENGINE(const DJS_ENGINE&) = delete;
	DJS_ENGINE& operator=(const DJS_ENGINE&) = delete;
	DJS_ENGINE(DJS_ENGINE&&) = delete;
	DJS_ENGINE& operator=(DJS_ENGINE&&) = delete;

	EngineContext& GetEngineContext();

	void Init();
	void Run();
	void Exit();
};