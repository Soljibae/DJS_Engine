#pragma once
#include <string>

class RenderManager;

class Shader {
    friend RenderManager;
private:
    unsigned int ID = 0;
    
    void LoadFromFiles(const char* vShaderCode, const char* fShaderCode);
    //void LoadFromFiles(std::string vertexPath, std::string fragmentPath);

    void Use() const;
    void Exit();

    void SetInt(const std::string& name, int value) const;
    void SetVec2(const std::string& name, float x, float y) const;
    void SetMat4(const std::string& name, const float* matrixPtr) const;
public:
};