//
// EPITECH PROJECT, 2018
// block.cpp
// File description:
// block member function
//

#include "block.hpp"

Block::Block(int pos) : Tile(BLOCK, pos)
{}

void Block::destroy_block(Map map)
{
	Bonus *bonus = new Bonus(this->get_pos());
	if (bonus->getbonus() != NONE)
		map.reinit_tile(bonus);
	else {
		bonus->~Bonus();
		map.rm_tile(this);
		this->~Block();
	}
}
