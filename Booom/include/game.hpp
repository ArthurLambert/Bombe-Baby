//
// EPITECH PROJECT, 2018
// game.hpp
// File description:
// game header
//

#ifndef GAME_HPP_
#define GAME_HPP_

#include "main.hpp"
#include <vector>

#define MAP_SIZE 17*17

enum type_of_tile
{
	BLOCK,
	INDESTRUCTIBLE,
	PLAYER,
	BOMBE
};

enum bonus_type
{
	SPEED,
	SEED,
	WEED
};

enum direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	CEMETERY
};

class Tile
{
public:
	Tile(type_of_tile type);
	~Tile() = default;
	type_of_tile get_type() const;

private:
	type_of_tile type;
};

class Block : public Tile
{
public :
	Block();
	~Block(Map map);
	~Block() = default;
	bonus_type getbonus() const;
	bool getis_destroyed() const;
	void destroy();

private:
	bonus_type bonus;
	bool is_destroyed;
};

class Map
{
public:
	Map(char* file);
	Map(); //test
	~Map() = default;
	void move(Player player, direction dir);
	void create(Player player, type_of_tile type)

private:
 vector< vector<Tile*> > map;
	int size;
};

class Player : public Tile
{
public:
	Player(vector<char> name, Map map);
	~Player() = default;
	void move(direction dir, Map map);
	void get_hit(Map map);
	void pick_bonus(Block bonus, Map map);
	int getpv() const;
	vector<char> getname() const;
	void drop_bombe(Map map);

private:
	int pv;
	vector<char> name;
	int nb_bombe;
	int speed;
	int power;
};

class Bombe : public Tile
{
public:
	Bombe(Map map);
	~Bombe() = default;
	void explode(Map map);

private:
	int tictac;
	int power;
};

#endif
