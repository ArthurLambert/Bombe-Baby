//
// EPITECH PROJECT, 2018
// player.cpp
// File description:
// player member function
//

#include "player.hpp"
#include "bombe.hpp"

Player::Player(std::vector<char> name, Map map) : Tile(PLAYER), pv(3), name(name), nb_bombe(1), speed(1), power(1)
{
	//config todo
}

void Player::move(direction dir, Map map)
{
	map.move_tile(this, dir);
}

void Player::get_hit(Map map)
{
	this->pv--;
	if (this->pv == 0) {
		map.rm_tile(this);
		this->~Player();
	}
}

void Player::pick_bonus(Bonus bonus, Map map)
{
	if (bonus.getbonus() == SPEED)
		this->speed++;
	map.rm_tile(&bonus);
}

int Player::getpv() const
{
	return this->pv;
}

std::vector<char> Player::getname() const
{
	return this->name;
}

void Player::drop_bombe(Map map)
{
	new Bombe(this, map);
}

direction Player::getimput()
{
	//??
	return UP;
}	
