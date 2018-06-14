//
// EPITECH PROJECT, 2018
// bonus.hpp
// File description:
// bonus header
//

#ifndef BONUS_HPP_
#define BONUS_HPP_

#include "map.hpp"
#include "tile.hpp"

class Bonus : public Tile
{
public:
	Bonus(int pos);
	~Bonus() = default;
	bonus_type getbonus();

private:
	bonus_type bonus;
};

#endif
