#include "BlinkingStar.h"


void BlinkingStar::update() {
	animatedImage->update();
	sprite.setTexture(*animatedImage->getCurrentTexture());
}

BlinkingStar::BlinkingStar(AnimatedImage * animatedImage, sf::Vector2f pos, float scalingFactor)
	:Star(animatedImage->getAssetPtr(), pos, scalingFactor), animatedImage(animatedImage) {

}