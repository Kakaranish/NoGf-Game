#pragma once
#include "Utility.h"
#include "Assets.h"
#include "Star.h"
#include "BlinkingStar.h"

class Background;

class Chunk: public sf::Drawable{
private:

	//Only once defined
	static sf::Vector2u blinkingStarSize; //OK
	static sf::Vector2u solidStarSize; //OK

	sf::FloatRect fRect; //OK //Using for checking if intersects with view

	Background * background; //OK
	std::vector<Star> solidStars; 
	std::vector<BlinkingStar> blinkingStars;

	void randStar(bool isBlinking, const unsigned& chunkNum);
public:
	Chunk(Background* background, const unsigned& chunkNum);
	~Chunk();
	void update();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const ;
};