#include "BackgroundView.h"

sf::Vector2f BackgroundView::getDivisionPoint()  {
	if (!isChanging) {
		std::cout << "Error! IsChanging = false " << std::endl;
		return sf::Vector2f(-1, -1);
	}

	return sf::Vector2f(0, abs(getOffset(&view).y) - bgCounter * backgroundHeight);
}

sf::Vector2f BackgroundView::getOffset(sf::View * view) const {
	return view->getCenter() - view->getSize() / 2.f;
}

void BackgroundView::update() {
	view.move(0, -movingSpeed);
	currentBg->update();

	std::cout << "Current y-offset = " << getOffset(&view).y << std::endl;

	int distToGenerate = 200;

	if (!readyForChanging && !isChanging && getOffset(&view).y - distToGenerate < -bgCounter * (int)backgroundHeight) {
		std::thread([&](Background*& nextBg, int bgCounter)->void {
			nextBg = new Background(this, sf::Vector2u(width, backgroundHeight),
			sf::Color(13, 13, 74, 255), sf::Vector2f(0, -(bgCounter+1) * (int)backgroundHeight));
		}, std::ref(nextBg), bgCounter).detach();
		
		readyForChanging = true;
	}

	if (readyForChanging && getOffset(&view).y < -bgCounter * (int)backgroundHeight) {
		isChanging = true;
	}

	//Here we gotta remove old background
	if (isChanging && getOffset(&view).y < -bgCounter * (int)backgroundHeight - (int)height ) {
		delete currentBg;
		currentBg = nextBg;
		nextBg = NULL;
		readyForChanging = false;
		isChanging = false;

		bgCounter++;

		std::cout << "Koniec zmiany! " << std::endl;		
	}

	if (isChanging) {
		sf::Vector2f divisionPoint = getDivisionPoint();
		float ratio = divisionPoint.y / height;


		nextBg->update();
		helpView.setViewport(sf::FloatRect(0, 0, 1, ratio));
		helpView.reset(sf::FloatRect(0, -bgCounter* (int)backgroundHeight - divisionPoint.y, width, divisionPoint.y));
	}
}

BackgroundView::BackgroundView(sf::Vector2f offset) {

	view.reset(sf::FloatRect(offset, sf::Vector2f(width, height)));

	fRect = std::move(sf::FloatRect());

	bgCounter = 0;
	currentBg = new Background(this, sf::Vector2u(width, backgroundHeight), sf::Color(13, 13, 74, 255));
	nextBg = NULL;
}

void BackgroundView::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.setView(view);
	if (!isChanging) {
		target.draw(*currentBg);
		return;
	}

	target.setView(view);
	target.draw(*currentBg);
	
	if (isChanging) {
		target.setView(helpView);
		target.draw(*nextBg);
	}
}