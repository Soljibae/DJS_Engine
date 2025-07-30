#pragma once
#include "TextureManager.h"
#include "Shader.h"
#include "GameObject.h"
#include <vector>

class DJS_ENGINE;

class RenderManager {
	friend DJS_ENGINE;
private:
	void Init();
	void Draw(const std::string& textureName,
		float x, float y, float width, float height,
		float uvX, float uvY, float uvWidth, float uvHeight);
	void Exit();

	TextureManager textureManager;
	Shader shader;
	unsigned int vao = 0;
	unsigned int vbo = 0;
	unsigned int ebo = 0;

	std::vector<GameObject*> renderQue;
public:
	void OnWindowResize(int newWidth, int newHeight);
};