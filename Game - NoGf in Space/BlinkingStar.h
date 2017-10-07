#pragma once
#include "Star.h"

class BlinkingStar : public Star {
private:
	AnimatedImage * animatedImage;
public:
	void update();
	BlinkingStar(AnimatedImage * animatedImage, sf::Vector2f pos, float scalingFactor = 1.f);
};
