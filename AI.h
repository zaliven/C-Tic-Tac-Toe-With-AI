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
};

class EasyAI : public AI {
public:
	pair<int, int> getComputerInput(Game* game) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
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