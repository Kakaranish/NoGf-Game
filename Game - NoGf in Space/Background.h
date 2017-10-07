#pragma once
#include "BlinkingStar.h"
#include "Chunk.h"


class BackgroundView;

class Background : public sf::Drawable {
private:

	BackgroundView * bgView;

	//Background info
	sf::Vector2u size; //size of the single background
	sf::Color color; //color of the background
	sf::RectangleShape rect; //the background rectangleshape
	
	std::vector<Chunk> chunkVector;

	//These variables gonna be common for every chunk on the map
	float chunkHeight;
	sf::Vector2u frameThickness;

public:
	void update();
	
	const BackgroundView* getBgPtr();
	const float& getChunkHeight();
	const sf::Vector2u& getFrameThickness();
	const sf::RectangleShape& getRect();

	Background(BackgroundView* bgView, sf::Vector2u size, sf::Color backgroundColor, sf::Vector2f offset = sf::Vector2f(0,0));
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
	const sf::Vector2u& getSize();
	~Background();
};

