#include "Background.h"
#include "BackgroundView.h"



int main(int argc, char * argv[]) {

	srand(static_cast<int>(time(NULL)));
	
	BackgroundView bgView(sf::Vector2f(0, backgroundHeight - height));
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window;
	window.create(sf::VideoMode(width, height, 32), "#NoGf in Space", sf::Style::None, settings);
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);

	b2Vec2 gravity(0, 0);
	b2World world(gravity);


	sf::Event event;
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
		}
		
		//Updating
		bgView.update();
		
		//World step
		world.Step(1 / 60.f, 8, 3);


		//Rendering
		window.clear(sf::Color(100, 100, 100));

		window.draw(bgView);

		window.display();

	}


	return 0;
}