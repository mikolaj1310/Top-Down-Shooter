#pragma once
#include "SFML\System\Vector2.hpp"
#include <math.h>

class Vector
{
public:
	//normalise vector
	static sf::Vector2f normalise(const sf::Vector2f &source);
	//Vector magnitude
	static float magnitude(sf::Vector2f vec);
private:
	Vector();
	~Vector();
};