#pragma once
#include "AnimatedImage.h"
#include "Entity.h"

class Star: public Entity {
protected:
	sf::FloatRect fRect;
	sf::Sprite sprite;
public:
	Star(ImageAsset * asset, sf::Vector2f pos, float scalingFactor = 1.f);
	sf::Sprite* getSpritePtr();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void update(){}
	const sf::FloatRect& getFloatRect();
};
