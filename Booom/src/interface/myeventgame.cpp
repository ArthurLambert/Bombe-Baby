//
// EPITECH PROJECT, 2018
// myeventgame.cpp
// File description:
// 
//

#include "myeventgame.hpp"

SAppContext::SAppContext()
{
	this->device = irr::createDevice(irr::video::EDT_SOFTWARE, irr::core::dimension2d<irr::u32>(SIZE_CASE*MAP_SIZE,SIZE_CASE*MAP_SIZE),16, false, false, false, 0);
	device->setWindowCaption(L"Bomberman Game");
	device->setResizable(true);
	this->driver = device->getVideoDriver();
	this->sceneManager = device->getSceneManager();
	this->guienv = device->getGUIEnvironment();
	this->counter = 0;
}

MyEventGame::MyEventGame(SAppContext & context) : Context(context)
{}

bool MyEventGame::OnEvent(const irr::SEvent& event)
{
	if (event.EventType == irr::EET_KEY_INPUT_EVENT &&
	    event.KeyInput.Key == irr::KEY_ESCAPE &&
	    event.KeyInput.PressedDown == false) {
		Context.device->closeDevice();
	}
	else if (event.EventType == irr::EET_KEY_INPUT_EVENT &&
		 event.KeyInput.Key == irr::KEY_UP &&
		 event.KeyInput.PressedDown == false) {
		Context.input = KEY_UP;
	}
	else if (event.EventType == irr::EET_KEY_INPUT_EVENT &&
		 event.KeyInput.Key == irr::KEY_DOWN &&
		 event.KeyInput.PressedDown == false) {
		Context.input = KEY_DOWN;
	}
	else if (event.EventType == irr::EET_KEY_INPUT_EVENT &&
		 event.KeyInput.Key == irr::KEY_RIGHT &&
		 event.KeyInput.PressedDown == false) {
		Context.input = KEY_RIGHT;
	}
	else if (event.EventType == irr::EET_KEY_INPUT_EVENT &&
		 event.KeyInput.Key == irr::KEY_LEFT &&
		 event.KeyInput.PressedDown == false) {
		Context.input = KEY_LEFT;
	}
	else if (event.EventType == irr::EET_KEY_INPUT_EVENT &&
		 event.KeyInput.Key == irr::KEY_SPACE &&
		 event.KeyInput.PressedDown == false) {
		Context.input = KEY_DROP;
	}
	else
		Context.input = KEY_NONE;
}
