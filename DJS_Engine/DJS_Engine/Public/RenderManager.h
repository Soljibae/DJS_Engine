#pragma once
#include "TextureManager.h"
#include "Shader.h"

class DJS_ENGINE;

class RenderManager {
	friend DJS_ENGINE;
private:
	void Init();
	void Draw();
	void Exit();

	

	TextureManager textureManager;
	Shader shader;
public:
	void OnWindowResize(int newWidth, int newHeight);
};