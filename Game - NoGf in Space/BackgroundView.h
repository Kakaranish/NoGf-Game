#pragma once
#include <thread>
#include <math.h>
#include "Utility.h"
#include "Background.h"



class BackgroundView : public sf::Drawable {
private:

	sf::FloatRect fRect;

	Background * currentBg;
	Background * nextBg;

	sf::View view;
	sf::View helpView;

	sf::Vector2u size = sf::Vector2u(width,height);
	float movingSpeed = 5 * 60/ 60.f;

	bool readyForChanging = false;
	bool isChanging = false;
	int bgCounter;

	sf::Vector2f getOffset(sf::View *view) const;
	sf::Vector2f getDivisionPoint() ;


public:
	BackgroundView(sf::Vector2f offset);
	void update();
	

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};