#pragma once
#include <iostream>
using std::pair;
class AI {
public:
	pair<int, int> virtual getComputerInput(class Game* game) = 0;
};

class EasyAI : public AI {
public:
	pair<int, int> getComputerInput(class Game* game) {
		pair<int, int> boxIndex;
		boxIndex.first = 0;
		boxIndex.second = 0;
		return boxIndex;
	}
};

class NormalAI : public AI {
public:
	pair<int, int> getComputerInput(class Game* game) {
		pair<int, int> boxIndex;

		return boxIndex;
	}
};

class HardAI : public AI {
public:
	pair<int, int> getComputerInput(class Game* game) {
		pair<int, int> boxIndex;

		return boxIndex;
	}
};