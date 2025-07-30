#include "RenderManager.h"
#include "DJS_Engine.h"
#include "GLAD/gl.h"
#include "GLM/glm.hpp"
#include "GLM/gtc/matrix_transform.hpp"
#include "GLM/gtc/type_ptr.hpp"

void RenderManager::Init()
{
	float screenWidth = DJS_ENGINE::GetInstance().GetEngineContext().windowManager->GetScreenWidth();
	float screenHeight = DJS_ENGINE::GetInstance().GetEngineContext().windowManager->GetScreenHeight();

	int iScreenWidth = static_cast<int>(screenWidth);
	int iScreenHeight = static_cast<int>(screenHeight);

	glViewport(0, 0, iScreenWidth, iScreenHeight);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glm::mat4 projection = glm::ortho(-screenWidth / 2.f, screenWidth / 2.f, -screenHeight / 2.f, screenHeight / 2.f, -1.0f, 1.0f);

	shader.LoadFromFiles("shader.vert", "shader.frag");
	shader.Use();
	shader.SetMat4("projection", glm::value_ptr(projection));
	shader.SetInt("spriteTexture", 0);
}

void RenderManager::OnWindowResize(int newWidth, int newHeight)
{
	glViewport(0, 0, newWidth, newHeight);

	float newWidthF = static_cast<float>(newWidth);
	float newHeightF = static_cast<float>(newHeight);

	shader.Use();
	glm::mat4 projection = glm::ortho(-newWidthF / 2.f, newWidthF / 2.f, -newHeightF / 2.f, newHeightF / 2.f, -1.0f, 1.0f);
	
	shader.SetMat4("projection", glm::value_ptr(projection));
}