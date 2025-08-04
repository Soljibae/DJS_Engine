#include "RenderManager.h"
#include "DJS_Engine.h"
#include "GLAD/gl.h"
#include "GLM/glm.hpp"
#include "GLM/gtc/matrix_transform.hpp"
#include "GLM/gtc/type_ptr.hpp"

void RenderManager::Init()
{
	float windowWidthF = DJS_ENGINE::GetInstance().GetEngineContext().windowManager->GetWindowWidth();
	float windowHeightF = DJS_ENGINE::GetInstance().GetEngineContext().windowManager->GetWindowHeight();

	this->windowWidth = static_cast<int>(windowWidthF);
	this->windowHeight = static_cast<int>(windowHeightF);
	this->screenWidth = static_cast<int>(DJS_ENGINE::GetInstance().GetEngineContext().windowManager->GetScreenWidth());
	this->screenHeight = static_cast<int>(DJS_ENGINE::GetInstance().GetEngineContext().windowManager->GetScreenHeight());
	this->zoom = cameraManager.GetCameraZoom();
	this->isFullScreen = DJS_ENGINE::GetInstance().GetEngineContext().windowManager->GetIsFullscreen();
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	const char* vertexShaderSource = R"GLSL(
    #version 330 core
    layout (location = 0) in vec4 vertex; // pos(2), tex(2)

    out vec2 TexCoords;

    uniform mat4 model;
	uniform mat4 view;
    uniform mat4 projection;
    uniform vec2 uv_offset;
    uniform vec2 uv_scale;

    void main() {
        TexCoords = (vertex.zw * uv_scale) + uv_offset;
        gl_Position = projection * view * model * vec4(vertex.xy, 0.0, 1.0);
    }
	)GLSL";

	const char* fragmentShaderSource = R"GLSL(
    #version 330 core
    in vec2 TexCoords;
    out vec4 color;

    uniform sampler2D spriteTexture;

    void main() { 
        color = texture(spriteTexture, TexCoords);
    }
	)GLSL";

	shader.LoadFromFiles(vertexShaderSource, fragmentShaderSource);
	shader.Use();
	UpdateViewportAndProjection();
	shader.SetInt("spriteTexture", 0);

	float vertices[] = {
		-0.5f, -0.5f, 0.0f, 0.0f,
		 0.5f, -0.5f, 1.0f, 0.0f,
		 0.5f,  0.5f, 1.0f, 1.0f,
		-0.5f,  0.5f, 0.0f, 1.0f
	};

	unsigned int indices[] = {
		0, 1, 2,
		2, 3, 0
	};

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);

	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);

	glBindVertexArray(0);
}

void RenderManager::Update(int width, int height, float zoom, bool isFullScreen)
{
	if (this->windowWidth != width || this->windowHeight != height || this->zoom != zoom || this->isFullScreen != isFullScreen)
	{
		this->windowWidth = width;
		this->windowHeight = height;
		this->zoom = zoom;
		this->isFullScreen = isFullScreen;

		UpdateViewportAndProjection();
	}
}

void RenderManager::Draw(const std::string& textureName,
	float x, float y, float width, float height,
	float uvX, float uvY, float uvWidth, float uvHeight)
{
	shader.Use();

	glm::mat4 model = glm::mat4(1.0f);

	model = glm::translate(model, glm::vec3(x, y, 0.f));

	model = glm::scale(model, glm::vec3(width, height, 1.0f));
	
	shader.SetMat4("view", glm::value_ptr(glm::translate(glm::mat4(1.0f), glm::vec3(-cameraManager.GetCameraPositionX(), -cameraManager.GetCameraPositionY(), 0.0f))));

	shader.SetMat4("model", glm::value_ptr(model));

	shader.SetVec2("uv_offset", uvX, uvY);

	shader.SetVec2("uv_scale", uvWidth, uvHeight);

	textureManager.BindTexture(textureName);

	glBindVertexArray(vao);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
}

void RenderManager::Exit()
{
	if (vao != 0) {
		glDeleteVertexArrays(1, &vao);
		glDeleteBuffers(1, &vbo);
		glDeleteBuffers(1, &ebo);

		vao = 0;
		vbo = 0;
		ebo = 0;
	}
}

void RenderManager::UpdateViewportAndProjection()
{
	float targetWidth;
	float targetHeight;

	if (this->isFullScreen)
	{
		targetWidth = static_cast<float>(this->screenWidth);
		targetHeight = static_cast<float>(this->screenHeight);
	}
	else
	{
		targetWidth = static_cast<float>(this->windowWidth);
		targetHeight = static_cast<float>(this->windowHeight);
	}
	glViewport(0, 0, static_cast<int>(targetWidth), static_cast<int>(targetHeight));

	shader.Use();
	glm::mat4 projection = glm::ortho(
		-targetWidth / 2.f / zoom,
		targetWidth / 2.f / zoom,
		-targetHeight / 2.f / zoom,
		targetHeight / 2.f / zoom,
		-1.0f,
		1.0f
	);

	shader.SetMat4("projection", glm::value_ptr(projection));

}