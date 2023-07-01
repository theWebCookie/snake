#pragma once
#include "Game.h"

class Game2: public Game {
public:
	Game2() : Game() {};
	void draw();
	void input();
};