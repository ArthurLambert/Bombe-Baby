//
// EPITECH PROJECT, 2018
// myeventgame.hpp
// File description:
// myeventgame header
//

#ifndef MYEVENTGAME_HPP_
#define MYEVENTGAME_HPP_

#include <irrlicht.h>
#include <iostream>
#include <fstream>
#include "map.hpp"

#define SIZE_CASE 32

enum input_key
{
	KEY_UP,
	KEY_DOWN,
	KEY_LEFT,
	KEY_RIGHT,
	KEY_DROP,
	KEY_NONE
};

enum unknown
{
	GUI_ID_QUIT_BUTTON = 101,
	GUI_ID_NEW_WINDOW_BUTTON,
	GUI_ID_GAME_BUTTON
};

class SAppContext
{
public :
	SAppContext();
	~SAppContext() = default;
	irr::IrrlichtDevice *device;
	irr::s32 counter;
	irr::scene::ISceneManager* sceneManager;
	irr::gui::IGUIEnvironment* guienv;
	irr::video::IVideoDriver* driver;
	input_key input;
};

class MyEventGame : public irr::IEventReceiver
{
public:
	MyEventGame(SAppContext & context);
	~MyEventGame() = default;
	virtual bool OnEvent(const irr::SEvent& event);

private:
	SAppContext &Context;
};

#endif
