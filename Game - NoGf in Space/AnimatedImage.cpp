#include "AnimatedImage.h"


void AnimatedImage::showNextImage() {
	currentStatus++;
	if (currentStatus >= asset->getCount())
		currentStatus = 0;
}

sf::Texture* AnimatedImage::getCurrentTexture() {
	return asset->getTexturePtr(currentStatus);
}

ImageAsset* AnimatedImage::getAssetPtr() {
	return asset;
}

AnimatedImage::AnimatedImage(ImageAsset * asset, float timeStep, bool autoPlay, unsigned startOffset) :
asset(asset), timeStep(timeStep), autoPlay(autoPlay), currentStatus(startOffset){
	
}

void AnimatedImage::play() {
	paused = false;
	clock.restart();
}
void AnimatedImage::stop() {
	paused = true;
}

void AnimatedImage::update() {
	if (clock.getElapsedTime().asSeconds() >= timeStep) {
		showNextImage();
		clock.restart();
	}
}