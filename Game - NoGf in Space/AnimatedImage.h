#pragma once
#include "ImageAsset.h"

class AnimatedImage {
private:
	ImageAsset * asset;
	sf::Clock clock;
	float timeStep;

	bool paused = false;
	bool autoPlay;

	unsigned currentStatus = 0;
	void showNextImage();
public:
	AnimatedImage(ImageAsset * asset, float timeStep = 2 / 6.f, bool autoPlay = true, unsigned startOffset = 0);
	void update();
	void play();
	void stop();
	ImageAsset * getAssetPtr();
	sf::Texture* getCurrentTexture();
};
