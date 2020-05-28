#pragma once
#include <iostream>
#include <time.h>
#include <thread>
#include <chrono>
using std::pair;

class Game;

class AI {
public:
	pair<int, int> virtual getComputerInput(Game* game) = 0;
	char** getBoardCopy(Game* game);
};

class EasyAI : public AI {
public:
	pair<int, int> getComputerInput(Game* game);
};



/*
algorithm:
test win moves for each available index with checkfinish function from *game
if no win moves, play a corner
if no corner, play center
if no center, play random
*/
class NormalAI : public AI {
public:
	pair<int, int> getComputerInput(Game* game) {
		pair<int, int> boxIndex;

		char** board = getBoardCopy(game);

		return boxIndex;
	}
};

class HardAI : public AI {
public:
	pair<int, int> getComputerInput(Game* game) {
		pair<int, int> boxIndex;

		return boxIndex;
	}
};