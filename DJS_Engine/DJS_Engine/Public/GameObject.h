#pragma once

class GameObject {
private:
public:
	virtual ~GameObject() = default;
	virtual void Init() {}
	virtual void LateInit() {}
	virtual void Update() {}
	virtual void LateUpdate() {} //for collsion
	virtual	void Exit() {}
};
