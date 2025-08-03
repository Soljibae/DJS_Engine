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
	void Update(int width, int height, float zoom, bool isFullScreen);
	void Exit();

	Shader shader;
	unsigned int vao = 0;
	unsigned int vbo = 0;
	unsigned int ebo = 0;

	//float* CreateProjection();

	std::vector<GameObject*> renderQue;

	int windowWidth; 
	int windowHeight;
	int screenWidth;
	int screenHeight;
	float zoom;
	bool isFullScreen;
public:
	TextureManager textureManager;
	void Draw(const std::string& textureName,
		float x, float y, float width, float height,
		float uvX = 0.f, float uvY = 0.f, float uvWidth = 1.f, float uvHeight = 1.f);
};