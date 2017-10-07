#include "Chunk.h"
#include "Background.h"

sf::Vector2u Chunk::blinkingStarSize = shiningStar.getTexturePtr(0)->getSize();
sf::Vector2u Chunk::solidStarSize = solidStar.getTexturePtr(0)->getSize();


Chunk::Chunk(Background* background,const unsigned& chunkNum): background(background) {

	sf::Vector2f mapOffset = background->getRect().getPosition();
	float chunkHeight = background->getChunkHeight();
	std::cout << "ChunkHeight = " << chunkHeight << std::endl;

	fRect = std::move(sf::FloatRect(0, mapOffset.y + chunkNum * chunkHeight, width,
		chunkHeight));
	
	//Blinking stars
	for (unsigned j = 0; j < (rand() % 6 + 3); j++)
		randStar(true, chunkNum);

	//Solid stars
	for (unsigned j = 0; j < (rand() % 10 + 20); j++)
		randStar(false, chunkNum);
	

}

Chunk::~Chunk() {
	//delete blinkingStars;
	//delete solidStars;
}

void Chunk::update() {
	for (unsigned i = 0; i < blinkingStars.size(); i++)
		blinkingStars.at(i).update();
}

void Chunk::draw(sf::RenderTarget& target, sf::RenderStates states) const  {

	for (unsigned j = 0; j < blinkingStars.size(); j++)
		target.draw(blinkingStars.at(j));
	for (unsigned j = 0; j < solidStars.size(); j++) 
		target.draw(solidStars.at(j));
}

void Chunk::randStar(bool isBlinking, const unsigned& chunkNum) {

	const sf::Vector2u& frameThickness = background->getFrameThickness();
	const float& chunkHeight = background->getChunkHeight();
	const sf::RectangleShape& rect = background->getRect();

	sf::Vector2u starSize = isBlinking ? blinkingStarSize : solidStarSize; //Depends on isBlinking
	sf::Vector2u maxPos(sf::Vector2u(width, chunkHeight)-2u*frameThickness);

	 //These variables need more global scope
	sf::Vector2f tempPos;
	sf::FloatRect tempStar, otherStar;
	bool tryAgain;

	sf::Vector2f offset = rect.getPosition();

	do {
		tryAgain = false;

		//drawing a TL corner of the star
		tempPos = sf::Vector2f(frameThickness.x + (rand() % maxPos.x) + offset.x
			, frameThickness.y + chunkHeight * chunkNum + (rand() % maxPos.y) + offset.y);

		//Star's sf::FloatRect we need to check if intersects with box of other star
		tempStar = sf::FloatRect(tempPos.x + (int)starSize.x / 2, tempPos.y + (int)starSize.y / 2, starSize.x, starSize.y);
		//std::cout << "TempStar pos = " << tempPos.x << "," << tempPos.y << std::endl;
		float vicinity = isBlinking ? 100 : 20;

		//Checking for an intersection with blinkingStar
		for (unsigned i = 0; i < blinkingStars.size(); i++) {

			//Center of the other star
			sf::Vector2f tPos = blinkingStars.at(i).getSpritePtr()->getPosition();

			//sf::FloatRect of the other star
			otherStar = sf::FloatRect(tPos.x - blinkingStarSize.x / 2 - vicinity,
				tPos.y - blinkingStarSize.y / 2 - vicinity,
				blinkingStarSize.x + 2 * vicinity, blinkingStarSize.y + 2 * vicinity);

			if (tempStar.intersects(otherStar)) {
				tryAgain = true;
				std::cout << "Intersection detected!" << std::endl;
				break;
			}
		}
		if (tryAgain)
			continue;

		//Checking for intersection with solidStars
		for (unsigned i = 0; i < solidStars.size(); i++) {

			//Center of the other star
			sf::Vector2f tPos = solidStars.at(i).getSpritePtr()->getPosition();

			//sf::FloatRect of the other star
			otherStar = sf::FloatRect(tPos.x - solidStarSize.x / 2 - vicinity,
				tPos.y - solidStarSize.y / 2 - vicinity,
				solidStarSize.x + 2 * vicinity, solidStarSize.y + 2 * vicinity);

			if (tempStar.intersects(otherStar)) {
				tryAgain = true;
				std::cout << "Intersection detected!" << std::endl;
				break;
			}
		}


	} while (tryAgain);


	float scalingFactor = (rand() % 7 + 8) / 10.f;
	if (isBlinking) {
		float blinkingInterval = (rand() % 30 + 100) / 100.f;
		blinkingStars.push_back(BlinkingStar(
			new AnimatedImage(&shiningStar, blinkingInterval, true, rand() % 8), tempPos, scalingFactor));
	}
	else
		solidStars.push_back(Star(&solidStar, tempPos, scalingFactor));

}