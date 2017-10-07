#include "ImageAsset.h"


ImageAsset::ImageAsset(std::string folderPath, std::string Basefilename, unsigned count) : count(count){

	std::stringstream filename;
	
	textureArr = new sf::Texture[count];

	
	for (unsigned i = 0; i < count; i++) {
		filename.str("");
		filename.clear();
		filename << folderPath << Basefilename << i + 1 << ".png";

		if (!textureArr[i].loadFromFile(filename.str())) {
			std::cout << "Unable to load texture! Error!" << std::endl;
			return;
		}
	}

	std::cout << "Asset " << Basefilename << " was correctly loaded" << std::endl;
}

sf::Texture * ImageAsset::getTexturePtr(unsigned num) {
	return &textureArr[num];
}

unsigned ImageAsset::getCount() {
	return count;
}