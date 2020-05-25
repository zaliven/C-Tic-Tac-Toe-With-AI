#pragma once
#include <iostream>
#include <time.h>
using std::pair;

class Game;

class AI {
public:
	pair<int, int> virtual getComputerInput(Game* game) = 0;
};

class EasyAI : public AI {
public:
	pair<int, int> getComputerInput(Game* game) {
		return game->getRandomAvailableIndex();
	}
};

class NormalAI : public AI {
public:
	pair<int, int> getComputerInput(Game* game) {
		pair<int, int> boxIndex;

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