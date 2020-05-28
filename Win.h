#pragma once
#include <iostream>
#include <typeinfo>
using std::cout;
using std::endl;
using std::string;

class Win {
protected:
	string type;
public:
	Win() = default;
	void virtual winningMessage() = 0;
};

class DiagonalWin : public Win {
public:
	DiagonalWin(string type) {
		this->type = type;
	}
	void winningMessage() {
		cout << "Win by " << type << typeid(*this).name() << endl;
	}
};

class ColumnWin : public Win {
private:
	int type;
public:
	ColumnWin(int type) {
		this->type = type;
	};
	void winningMessage() {
		cout << "Win by " << typeid(*this).name() << " in column " << type << endl;
	}
};

class RowWin : public Win {
private:
	int type;
public:
	RowWin(int type) {
		this->type = type;
	};
	void winningMessage() {
		cout << "Win by " << typeid(*this).name() << " in row " << type << endl;
	}
};