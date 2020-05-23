#pragma once
#include <iostream>
#include "Win.h"
#include "AI.h"

#define PLAYER_ONE true
#define PLAYER_TWO false
#define EASY 1
#define NORMAL 2
#define HARD 3
#define INSANE 4

#define COMPUTER 1
#define HUMAN 2

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::pair;

class Game {
private:
	const int rowCount = 3;
	const int colCount = 3;
	char** board;
	bool player = PLAYER_ONE;
	string playerOne = "Player One";
	string playerTwo = "Player Two";
	int humanPlayer;
	int opponent;
	int difficulty;
	Win* win;
	AI* computer;
	bool gameOngoing = true;

public:
	void Initialize();
	pair<int, int> getPlayerInput();
	pair<int, int> getRowCol(int input);
	bool checkIndex(pair<int, int> rowCol);
	bool checkFinish();
	bool checkTie();
	bool checkDiagonalRight();
	bool checkDiagonalLeft();
	bool checkColumn(int col);
	bool checkRow(int row);
	void printWinner();
	void printTie();
	void printBoard();
	void endTurn();
	bool promptRestart();
	void clearBoard();
	void setComputerParameters();

	Game();
	~Game();
};