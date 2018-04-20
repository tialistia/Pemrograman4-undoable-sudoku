#include "stdafx.h"
#include "Command.h"
#include "Sudoku.h"
#include "Invoker.h"
#include "ConcreteCommand.h"
#include <cstdio>

using namespace std;
Sudoku *sudoku;
Invoker *controller;
Command *cmd;

void initGame() {
	sudoku->initBoard();
	sudoku->printBoard();
}

int main()
{
	sudoku = new Sudoku;
	controller = new Invoker;
	initGame();

	cmd = new FillCommand(sudoku, 2, 3, 8);
	controller->setCommand(cmd);
	controller->executeCommand();

	sudoku->printBoard();

	controller->undoCommand();

	sudoku->printBoard();

	getchar();
    return 0;
}
