#pragma once
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <Box2D\Box2D.h>
#include <SFML\Graphics.hpp>

const unsigned width = 800, height = 600; //screenSize
const float pixels_to_meters = 1 / 100.f, meters_to_pixels = 1 / pixels_to_meters;

const unsigned backgroundHeight = height * 4;

b2Vec2 convertsfVector(sf::Vector2f vec);
sf::Vector2f convertB2Vec(b2Vec2 vec);

float toDeg(float rad);
float toRad(float deg);

enum EntityType {
	PLAYER
};


