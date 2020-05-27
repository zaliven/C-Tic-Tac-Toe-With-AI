#include "AI.h"
#include "Game.h"

char** AI::getBoardCopy(Game* game) {
	char** gameBoard = game->getBoard();
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
}

pair<int, int> EasyAI::getComputerInput(Game* game) {
	std::this_thread::sleep_for(std::chrono::seconds(1));
	return game->getRandomAvailableIndex();
}