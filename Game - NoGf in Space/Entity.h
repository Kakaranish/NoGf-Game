#pragma once
#include "Utility.h"

class Entity : public sf::Drawable {
protected:
	EntityType type;
public:
	//virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void update() = 0;
	EntityType getType() { return type;};
};
