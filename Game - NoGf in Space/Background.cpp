#include "BackgroundView.h"
#include "Background.h"

//Getters
const float & Background::getChunkHeight() {
	return chunkHeight;
}

const sf::Vector2u & Background::getFrameThickness() {
	return frameThickness;
}

const sf::RectangleShape & Background::getRect() {
	return rect;
}

const sf::Vector2u& Background::getSize() {
	return size;
}

const BackgroundView* Background::getBgPtr() {
	return bgView;
}

Background::~Background() {
	//for (int i = 0; i < chunkVector.size(); i++)
	//	delete chunkVector.at(i);
	chunkVector.clear();
}


Background::Background(BackgroundView* bgView, sf::Vector2u size, sf::Color backgroundColor, sf::Vector2f offset) :
	size(size), color(backgroundColor), bgView(bgView) {

	frameThickness = sf::Vector2u(45, 20);

	rect.setSize((sf::Vector2f)size);
	rect.setPosition(offset);
	rect.setFillColor(color);
	

	unsigned chunkAmount = (unsigned)((float)size.y / height);
	chunkHeight = (float)size.y / (float)chunkAmount;

	
	for (int i = 0; i < chunkAmount; i++) 
		chunkVector.push_back(std::move(Chunk(this, i)));
}

void Background::update() {
	for (unsigned i = 0; i < chunkVector.size(); i++)
		chunkVector.at(i).update();
}

void Background::draw(sf::RenderTarget & target, sf::RenderStates states) const {
	target.draw(rect);
	for (unsigned i = 0; i < chunkVector.size(); i++)
		target.draw(chunkVector.at(i));
}