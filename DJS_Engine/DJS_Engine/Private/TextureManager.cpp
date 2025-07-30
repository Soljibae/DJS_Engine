#include "TextureManager.h"
#include <GLAD/gl.h>
#include "STBImage/stb_image.h"
#include <iostream>

void TextureManager::LoadTexture(std::string name, std::string path)
{
    if (textureMap.count(name))
    {
        return;
    }

    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);

    GLenum format = GL_RGB;
    if (nrChannels == 1) format = GL_RED;
    else if (nrChannels == 4) format = GL_RGBA;

    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(data);
    textureMap[name] = textureID;
}

void TextureManager::BindTexture(std::string name, unsigned int textureUnit)
{
    GLuint textureID = textureMap[name];
    if (textureID != 0) {
        glActiveTexture(textureUnit);
        glBindTexture(GL_TEXTURE_2D, textureID);
    }
}

void TextureManager::UnloadAll()
{
    for (auto const& [name, id] : textureMap) {
        glDeleteTextures(1, &id);
    }
    textureMap.clear();
}
