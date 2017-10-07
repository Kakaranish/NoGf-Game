#include "Utility.h"

sf::Vector2f convertB2Vec(b2Vec2 vec) {
	return sf::Vector2f(vec.x * meters_to_pixels, vec.y * meters_to_pixels);
}
float toDeg(float rad) {
	return rad * 180 / b2_pi;
}
float toRad(float deg) {
	return deg / 180.f *b2_pi;
}

b2Vec2 convertsfVector(sf::Vector2f vec) {
	return b2Vec2(vec.x * meters_to_pixels, vec.y * meters_to_pixels);
}
