#pragma once
#include "WindowManager.h"

struct EngineContext {
	WindowManager* windowManager = nullptr;
};

class DJS_ENGINE {
private:
	DJS_ENGINE(){}

	~DJS_ENGINE() {}

	bool shouldRun = true;

	EngineContext engineContext;
	WindowManager windowManager;
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