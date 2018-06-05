//
// EPITECH PROJECT, 2018
// game.cpp
// File description:
// game
//

#include "game.hpp"

Game::Game()
{
	this->map = new Map();
	this->play();
}

void Game::play()
{
	this->map->display_map_on_console();
}

void Game::refresh_map()
{
	//function called by the loop in play
}





















/*


Tile::Tile(type_of_tile type) : type(type)
{}

type_of_tile Tile::get_type()
{
	return this.type;
}

Block::Block() : Tile(BLOCK), is_destroyed(0)
{
	bonus = SPEED;//random bonus
}

Block::~Block(Map map)
{
	map.move(this, CEMETERY);
}

bonus_type getbonus() const
{
	return this.bonus;
}

bool getis_destroyed() const
{
	return this.is_destroyed;
}

void destroy()
{
	this.is_destroyed = 1;
}

Player::Player(vector<char> name) : Tile(PLAYER), name(name), pv(3), speed(1), power(1), nb_bombe(1)
{}

void Player::move(direction dir, Map map)
{
	map.move_player(this, dir);
}

void Player::get_hit(Map map)
{
	this.pv -= 1;
	if (pv = 0)
		this.move(cemetery, map);
}

void Player::pick_bonus(Block block)
{
	bonus_type bonus = block.getbonus();
	switch (bonus) {
	case SPEED:
		this.speed += 1;
		break;
	}
	//destructor of block todo
}

int Player::getpv() const
{
	return this.pv;
}

vector<char> Player::getname() const
{
	return this.name;
}

void Player::drop_bombe(Map map)
{
	Bombe(this, map);
}

Bombe::Bombe(Player player, Map map) : Tile(BOMBE), tictac(5)
{
	map.create(player, BOMBE);
}

void Bombe::explode()
{
	//chek a timer(tictac) heach time it is called
}
*/
