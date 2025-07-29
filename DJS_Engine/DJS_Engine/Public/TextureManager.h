#pragma once
#include <string>
#include <map>

class TextureManager {
public:
	void LoadTexture(std::string name, std::string path);
	void BindTexture(std::string name, unsigned int textureUnit = 0);
	void UnloadAll();
private:
	std::map<std::string, unsigned int> textureMap;
};