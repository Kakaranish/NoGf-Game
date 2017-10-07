#include "Star.h"


Star::Star(ImageAsset * asset, sf::Vector2f pos, float scalingFactor) {
	
	sf::Vector2u starSize = asset->getTexturePtr(0)->getSize();
	sprite.setTexture(*asset->getTexturePtr(0));
	sprite.setOrigin((sf::Vector2f)(starSize / 2u));
	sprite.setPosition((sf::Vector2f)pos);
	sprite.setScale(scalingFactor, scalingFactor);


	fRect = std::move(sf::FloatRect(sprite.getPosition()- (sf::Vector2f)(starSize/2u), (sf::Vector2f)(starSize)));
	std::cout << "l = " << fRect.left << ", t = " << fRect.top << ", w = " << fRect.width << ", h = " << fRect.height << std::endl;
}

const sf::FloatRect& Star::getFloatRect() {
	return fRect;
}

sf::Sprite* Star::getSpritePtr() {
	return &sprite;
}

void Star::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(sprite);
}