#pragma once
#include <iostream>
#include "Win.h"
#include <vector>

#define PLAYER_ONE 1
#define PLAYER_TWO 2
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
using std::vector;

class AI;

class Game {
private:
	const int rowCount = 3;
	const int colCount = 3;
	char** board;
	int player = PLAYER_ONE;
	string playerOne;
	string playerTwo;
	int humanPlayer;
	int opponent;
	int difficulty;
	Win* win;
	AI* computer;
	bool gameOngoing = true;

public:
	vector<pair<int, int>> availableIndexes;

	void Initialize();
	pair<int, int> getPlayerInput();
	pair<int, int> getRowCol(int input);
	bool checkIndex(pair<int, int> rowCol);
	void addMark(pair<int, int> boxIndex);
	bool checkFinish(char** board);
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
	void initializeBoard();
	void setComputerParameters();
	void deleteWin();
	pair<int, int> getRandomAvailableIndex();
	char** getBoard();

	Game();
	~Game();
};