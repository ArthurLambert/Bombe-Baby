//
// EPITECH PROJECT, 2018
// player.cpp
// File description:
// player member function
//

#include "player.hpp"
#include "bombe.hpp"
#include "bonus.hpp"

Player::Player(Map* map, int pos) : Tile(PLAYER, pos), pv(3), nb_bombe(1), speed(1), power(1)
{
	map->add_tile(this);
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

void Player::pick_bonus(Bonus *bonus, Map map)
{
	if (bonus->getbonus() == SPEED)
		this->speed++;
	map.rm_tile(bonus);
	bonus->~Bonus();
}

int Player::getpv() const
{
	return this->pv;
}

void Player::drop_bombe(Map map)
{
	if (this->nb_bombe != 0) {
		new Bombe(this->get_pos(), map, this->power);
		this->nb_bombe--;
	}
}

void Player::getinput(Map &map, input_key input)
{
	for (auto &i : (map.get_tile(this->get_pos())).getstack()) {
		if (i->get_type() == FIRE)
			this->get_hit(map);
		if (i->get_type() == BONUS)
			this->pick_bonus((Bonus *)i, map);
	}
	switch(input) {
	case KEY_UP :
		this->move(UP, map);
		break;
	case KEY_DOWN :
		this->move(DOWN, map);
		break;
	case KEY_LEFT :
		this->move(LEFT, map);
		break;
	case KEY_RIGHT :
		this->move(RIGHT, map);
		break;
	case KEY_DROP :
		this->drop_bombe(map);
		break;
	}
}
