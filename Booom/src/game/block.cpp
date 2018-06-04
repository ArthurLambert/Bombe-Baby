//
// EPITECH PROJECT, 2018
// block.cpp
// File description:
// block member function
//

#include "block.hpp"
#include "bombe.hpp"

Block::Block() : Tile(BLOCK)
{}

void Block::destroy_block(Map map)
{
	Bonus *bonus = new Bonus();
	if (bonus->getbonus() != NONE)
		map.reinit_tile(this, bonus, BONUS);
	else
		bonus->~Bonus();
}
