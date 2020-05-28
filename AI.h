#pragma once
#include <iostream>
#include <time.h>
#include <thread>
#include <chrono>
using std::pair;

class Game;

class AI {
protected:
	Game* gameCopy;
	char computerMark;
	char playerMark;
public:
	AI() = default;
	pair<int, int> virtual getComputerInput() = 0;
	bool testWinMove(char** board, char mark, pair<int, int> boxIndex);
	char** getBoardCopy();
};

class EasyAI : public AI {
public:
	EasyAI(Game* game);
	pair<int, int> getComputerInput();
};

class NormalAI : public AI {
public:
	NormalAI(Game* game, char mark);
	pair<int, int> getComputerInput();
};

class HardAI : public AI {
public:
	HardAI(Game* game, char mark);
	pair<int, int> getComputerInput();
	bool testForkMove(char** board, char mark, pair<int, int> boxIndex);
};