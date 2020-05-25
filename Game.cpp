#include "Game.h"
#include "AI.h"
/*
	TODO:
	AI - Waits 1 second to make a move. 
	Easy - Vector that updates each round and has all available indexes. Moves randomly
	Medium - AI Code
	Hard - Unbeatable
	https://mblogscode.com/2016/06/03/python-naughts-crossestic-tac-toe-coding-unbeatable-ai/
*/

Game::Game() {
	board = new char* [rowCount];
	char index = '1';
	for (int i = 0; i < rowCount; i++) {
		board[i] = new char[colCount];
	}
	
	initializeBoard();
}

Game::~Game() {
	delete win;
	delete board;
}

void Game::Initialize() {
	initializeBoard();
	do
	{
		system("cls");
		cout << "Welcome To Tic Tac Toe" << endl;
		cout << "Play against computer - (1)" << endl << "Play against another player - (2)" << endl << "Your choice: ";
		cin >> opponent;
	} while (opponent != COMPUTER && opponent != HUMAN);

	if (opponent == COMPUTER) {
		setComputerParameters();
	}

	do
	{
		pair<int, int> boxIndex = (opponent == 1 && player != humanPlayer) ? computer->getComputerInput(this) : getPlayerInput();
		addMark(boxIndex);
		if (checkFinish()) {
			gameOngoing = false;
			if (win != NULL) {
				printWinner();
			}
			else {
				printTie();
			}
			gameOngoing = promptRestart();
			if (gameOngoing) {
				Initialize();
			}
		}
		endTurn();
	} while (gameOngoing);
}

pair<int, int> Game::getRandomAvailableIndex() {

	pair<int, int> IndexToReturn;
	srand(time(NULL));
	int index = rand() % (availableIndexes.size() - 1);
	IndexToReturn = availableIndexes[index];
	return availableIndexes[index];	
}

void Game::addMark(pair<int, int> boxIndex)
{
	board[boxIndex.first][boxIndex.second] = player == PLAYER_ONE ? 'X' : 'O';
	availableIndexes.erase(find(availableIndexes.begin(), availableIndexes.end(), boxIndex));
}

pair<int, int> Game::getPlayerInput() {
	int input;
	int valid = true;
	pair<int, int> rowCol;
	do
	{
		printBoard();
		if (!valid) {
			cout << "Invalid cell number!" << endl;
		}
		cout << "Choose a number: ";
		cin >> input;
		rowCol = getRowCol(input);
		valid = checkIndex(rowCol);
	} while (!valid);
	return rowCol;
}

bool Game::checkIndex(pair<int, int> rowCol) {
	bool isValid = isdigit(board[rowCol.first][rowCol.second]);
	return isValid;
}

pair<int, int> Game::getRowCol(int input) {
	pair<int, int> boxIndex;
	int row = 0;
	while (input > 3)
	{
		input -= 3;
		row++;
	}
	boxIndex.first = row;
	boxIndex.second = input - 1;
	return boxIndex;
}

bool Game::promptRestart() {
	char choice;
	do {
		cout << "Would you like to restart? (y/n): ";
		cin >> choice;
		cout << endl;
	} while (choice != 'n' && choice != 'y');
	return choice == 'y' ? true : false;	
}

void Game::initializeBoard() {
	char index = '1';
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < colCount; j++) {
			pair<int, int> pairIndex;
			pairIndex.first = i;
			pairIndex.second = j;
			availableIndexes.push_back(pairIndex);

			board[i][j] = index;
			index++;
		}
	}
}

bool Game::checkFinish() {
	int i;
	int j;
	//check rows
	for (i = 0; i < rowCount; i++) {
		if (isdigit(board[i][0])) {
			continue;
		}
		if (checkRow(i)) {
			win = new RowWin(i+1);
			return true;
		}
	}
	//check columns
	for (i = 0; i < colCount; i++) {
		if (isdigit(board[0][i])) {
			continue;
		}
		if (checkColumn(i)) {
			win = new ColumnWin(i+1);
			return true;
		}
	}
	//check diagonal
	if (checkDiagonalRight()) {
		win = new DiagonalWin("Right");
		return true;
	}
	if (checkDiagonalLeft()) {
		win = new DiagonalWin("Left");
		return true;
	}

	if (checkTie()) {
		return true;
	}
	return false;
}

bool Game::checkTie() {
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < colCount; j++) {
			if (isdigit(board[i][j])) {
				return false;
			}
		}
	}
	return true;
}

bool Game::checkDiagonalRight() {
	bool diagonalWin = false;
	if (isdigit(board[0][0])) return false;
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) diagonalWin = true;
	return diagonalWin;
}

bool Game::checkDiagonalLeft() {
	bool diagonalWin = false;
	if (isdigit(board[2][0])) return false;
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) diagonalWin = true;
	return diagonalWin;
}

bool Game::checkColumn(int col) {
	for (int i = 0; i < colCount - 1; i++) {
		if (board[i][col] != board[i + 1][col]) {
			return false;
		}
	}
	return true;
}

bool Game::checkRow(int row) {
	for (int i = 0; i < rowCount - 1; i++) {
		if (board[row][i] != board[row][i + 1]) {
			return false;
		}
	}
	return true;
}

void Game::printWinner() {
	printBoard();
	cout << ((player == 1) ? playerOne : playerTwo) << " is the winner!" << endl;
	win->winningMessage();
	cout << endl;
}

void Game::printTie() {
	printBoard();
	cout << "Tie ..." << endl;
}

void Game::printBoard() {
	system("cls");
	// player == true -> player one string
	cout << ((player == 1) ? playerOne : playerTwo) << "\'s turn";
	cout << endl;


	cout << "     |     |     " << endl;
	cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;

	cout << "     |     |     " << endl << endl;
}

// switch player turn
void Game::endTurn() {
	player = player == 1 ? PLAYER_TWO : PLAYER_ONE;
}

void Game::setComputerParameters() {
	do
	{
		system("cls");
		cout << "Choose difficulty:" << endl << "(1) Easy" << endl << "(2) Normal" << endl << "(3) Hard" << endl << "(4) INSANE" << endl << "Difficulty: ";
		cin >> difficulty;
	} while (difficulty != EASY && difficulty != NORMAL && difficulty != HARD && difficulty != INSANE);
	
	switch (difficulty)
	{
	case EASY:
		computer = new EasyAI;
		break;
	case NORMAL:
		computer = new NormalAI;
		break;
	default:
		computer = new HardAI;
		break;
	}

	// on insane difficulty player is unable to go first unless number is entered
	if (difficulty == INSANE) {
		humanPlayer = 2;
	}
	else
	{
		do
		{
			system("cls");
			cout << "Would you like to go first or second?" << endl << "(1) First" << endl << "(2) Second" << endl;
			cout << "Your choice: ";
			cin >> humanPlayer;
		} while (humanPlayer != 1 && humanPlayer != 2);
	}
}