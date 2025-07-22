#pragma once
#include "WindowManager.h"

class DJS_ENGINE {
private:
	DJS_ENGINE(){}

	~DJS_ENGINE() {}

	bool shouldRun = true;

	WindowManager windowManager;
public:
	static DJS_ENGINE& GetIncetance()
	{
		static DJS_ENGINE instance;
		return instance;
	}

	DJS_ENGINE(const DJS_ENGINE&) = delete;
	DJS_ENGINE& operator=(const DJS_ENGINE&) = delete;
	DJS_ENGINE(DJS_ENGINE&&) = delete;
	DJS_ENGINE& operator=(DJS_ENGINE&&) = delete;

	void Init();
	void Run();
	void Exit();
};