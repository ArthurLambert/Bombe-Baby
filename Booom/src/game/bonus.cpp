//
// EPITECH PROJECT, 2018
// bonus.cpp
// File description:
// bonus member function
//

#include "bonus.hpp"
#include <cstdlib>
#include <ctime>

Bonus::Bonus(int pos) : Tile(BONUS, pos)
{
	int random;

	std::srand(std::time(nullptr));
	random = std::rand()%3;
	this->bonus = (bonus_type)random;
}

bonus_type Bonus::getbonus()
{
	return this->bonus;
}
