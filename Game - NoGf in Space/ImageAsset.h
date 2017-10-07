#pragma once
#include "Utility.h"
#include <string>
#include <sstream>

class ImageAsset {
private:
	sf::Texture * textureArr;
	unsigned count;
public:
	ImageAsset(std::string folderPath, std::string Basefilename, unsigned count);
	sf::Texture * getTexturePtr(unsigned num);
	unsigned getCount();
};
