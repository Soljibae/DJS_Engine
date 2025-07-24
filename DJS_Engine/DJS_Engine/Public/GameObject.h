#pragma once

class GameObject {
private:
	virtual ~GameObject() = default;

public:
	virtual void Init() {}
	virtual void LateInit() {}
	virtual void Update() {}
	virtual void LateUpdate() {} //for collsion
	virtual	void Exit() {}
};
