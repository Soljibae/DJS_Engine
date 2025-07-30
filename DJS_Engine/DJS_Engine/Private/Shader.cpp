#include "Shader.h"
#include "RenderManager.h"
#include "GLM/glm.hpp"
#include "GLAD/gl.h"
#include <fstream>
#include <sstream>
#include <iostream>

void Shader::LoadFromFiles(const char* vShaderCode, const char* fShaderCode)
{
    GLuint vertex, fragment;

    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, NULL);
    glCompileShader(vertex);

    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, NULL);
    glCompileShader(fragment);

    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);

    glDeleteShader(vertex);
    glDeleteShader(fragment);

}

//void Shader::LoadFromFiles(std::string vertexPath, std::string fragmentPath)
//{
//    std::string vertexCode;
//    std::string fragmentCode;
//    std::ifstream vShaderFile;
//    std::ifstream fShaderFile;
//
//    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
//    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
//    try {
//        vShaderFile.open(vertexPath);
//        fShaderFile.open(fragmentPath);
//        std::stringstream vShaderStream, fShaderStream;
//        vShaderStream << vShaderFile.rdbuf();
//        fShaderStream << fShaderFile.rdbuf();
//        vShaderFile.close();
//        fShaderFile.close();
//        vertexCode = vShaderStream.str();
//        fragmentCode = fShaderStream.str();
//    }
//    catch (std::ifstream::failure& e) {
//        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
//    }
//    const char* vShaderCode = vertexCode.c_str();
//    const char* fShaderCode = fragmentCode.c_str();
//
//    GLuint vertex, fragment;
//
//    vertex = glCreateShader(GL_VERTEX_SHADER);
//    glShaderSource(vertex, 1, &vShaderCode, NULL);
//    glCompileShader(vertex);
//
//    fragment = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(fragment, 1, &fShaderCode, NULL);
//    glCompileShader(fragment);
//
//    ID = glCreateProgram();
//    glAttachShader(ID, vertex);
//    glAttachShader(ID, fragment);
//    glLinkProgram(ID);
//
//    glDeleteShader(vertex);
//    glDeleteShader(fragment);
//
//}

void Shader::Use() const
{
    glUseProgram(ID);
}

void Shader::Exit()
{
    glLinkProgram(ID);
}

void Shader::SetInt(const std::string& name, int value) const
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::SetVec2(const std::string& name, float x, float y) const
{
    glm::vec2 value = { x, y };
    glUniform2fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
}

void Shader::SetMat4(const std::string& name, const float* matrixPtr) const
{
    glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, matrixPtr);
}