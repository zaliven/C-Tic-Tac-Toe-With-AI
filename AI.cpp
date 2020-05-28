#include "AI.h"
#include "Game.h"

pair<int, int> EasyAI::getComputerInput() {
	std::this_thread::sleep_for(std::chrono::seconds(1));
	return gameCopy->getRandomAvailableIndex();
}

EasyAI::EasyAI(Game* game) {
	gameCopy = game;
}

NormalAI::NormalAI(Game* game, char mark) {
	gameCopy = game;
	computerMark = mark;
	playerMark = mark == 'X' ? 'O' : 'X';
}

HardAI::HardAI(Game* game, char mark) {
	gameCopy = game;
	computerMark = mark;
	playerMark = mark == 'X' ? 'O' : 'X';
}

bool AI::testWinMove(char** board, char mark, pair<int, int> boardIndex) {
	/*
	board - copy of game board to test win move
	boardIndex - test mark on boardIndex of board
	*/
	bool isWin = false;
	char tempIndex = board[boardIndex.first][boardIndex.second];
	board[boardIndex.first][boardIndex.second] = mark;
	isWin = gameCopy->checkFinish(board, false);
	if (!isWin) {
		// revert board to previous state
		board[boardIndex.first][boardIndex.second] = tempIndex;
	}
	return isWin;
}

pair<int, int> NormalAI::getComputerInput() {
	std::this_thread::sleep_for(std::chrono::seconds(1));
	char** tempBoard = getBoardCopy();
	pair<int, int> tempIndex;

	//Check computer win moves
	for (int i = 1; i <= 9; i++) {
		tempIndex = gameCopy->getRowCol(i);
		if (isdigit(tempBoard[tempIndex.first][tempIndex.second]) && testWinMove(tempBoard, computerMark, tempIndex)) {
			return tempIndex;
		}
	}
	//Check player win moves
	for (int i = 1; i <= 9; i++) {
		tempIndex = gameCopy->getRowCol(i);
		if (isdigit(tempBoard[tempIndex.first][tempIndex.second]) && testWinMove(tempBoard, playerMark, tempIndex)) {
				return tempIndex;
		}

	}
	// Play a corner
	for (int i = 1; i <= 9; i += 2) {
		tempIndex = gameCopy->getRowCol(i);
		if (isdigit(tempBoard[tempIndex.first][tempIndex.second])) {
			return tempIndex;
		}
	}
	// Play center
	tempIndex = gameCopy->getRowCol(5);
	if (isdigit(tempBoard[tempIndex.first][tempIndex.second])) {
		return tempIndex;
	}
	// Play a side
	for (int i = 2; i <= 9; i += 2) {
		tempIndex = gameCopy->getRowCol(i);
		if (isdigit(tempBoard[tempIndex.first][tempIndex.second])) {
			return tempIndex;
		}
	}
}

bool HardAI::testForkMove(char** board, char mark, pair<int, int> boxIndex) {
	int winningMoves = 0;
	pair<int, int> tempIndex;
	for (int i = 1; i <= 9; i++) {
		if (isdigit(board[tempIndex.first][tempIndex.second]) && testWinMove(board, computerMark, tempIndex)) {
			winningMoves++;
		}
	}
	return winningMoves >= 2;
}

pair<int, int> HardAI::getComputerInput() {
	std::this_thread::sleep_for(std::chrono::seconds(1));
	char** tempBoard = getBoardCopy();
	pair<int, int> tempIndex;

	//Check computer win moves
	for (int i = 1; i <= 9; i++) {
		tempIndex = gameCopy->getRowCol(i);
		if (isdigit(tempBoard[tempIndex.first][tempIndex.second]) && testWinMove(tempBoard, computerMark, tempIndex)) {
			return tempIndex;
		}
	}
	//Check player win moves
	for (int i = 1; i <= 9; i++) {
		tempIndex = gameCopy->getRowCol(i);
		if (isdigit(tempBoard[tempIndex.first][tempIndex.second]) && testWinMove(tempBoard, playerMark, tempIndex)) {
			return tempIndex;
		}

	}
	// Test computer fork moves
	for (int i = 1; i <= 9; i++) {
		tempIndex = gameCopy->getRowCol(i);
		if (isdigit(tempBoard[tempIndex.first][tempIndex.second]) && testForkMove(tempBoard, computerMark, tempIndex)) {
			return tempIndex;
		}
	}
	// Test player fork moves
	for (int i = 1; i <= 9; i++) {
		tempIndex = gameCopy->getRowCol(i);
		if (isdigit(tempBoard[tempIndex.first][tempIndex.second]) && testForkMove(tempBoard, computerMark, tempIndex)) {
			return tempIndex;
		}
	}
	// Play center
	tempIndex = gameCopy->getRowCol(5);
	if (isdigit(tempBoard[tempIndex.first][tempIndex.second])) {
		return tempIndex;
	}
	// Play a corner
	for (int i = 1; i <= 9; i += 2) {
		tempIndex = gameCopy->getRowCol(i);
		if (isdigit(tempBoard[tempIndex.first][tempIndex.second])) {
			return tempIndex;
		}
	}
	// Play a side
	for (int i = 2; i <= 9; i += 2) {
		tempIndex = gameCopy->getRowCol(i);
		if (isdigit(tempBoard[tempIndex.first][tempIndex.second])) {
			return tempIndex;
		}
	}
}

char** AI::getBoardCopy() {
	char** gameBoard = gameCopy->getBoard();
	char** board = new char* [3];
	char index = '1';
	for (int i = 0; i < 3; i++) {
		board[i] = new char[3];
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = gameBoard[i][j];
		}
	}
	return board;
}


