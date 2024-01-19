#ifndef NBTICTACTOE_H_
#define NBTICTACTOE_H_
#include "TicTacToe.h"
#include "Focus.h" 
class NBTicTacToe {
public:
	void play();
	void getXMove(char player, int&, int&);
	void getOMove(char playr, int&, int&);
	void displayBoards();
	void changeBoard(int& x, int& y);
	bool isValidBoard(int x, int y);
	NBTicTacToe() {
		int min = 1;
		int max = 3;
		int row, col;
		do {
			row = (rand() % (max - min + 1)) + min;
			col = (rand() % (max - min + 1)) + min;
		} while (isValidBoard(row, col) == false);

		currentBoard.x = row - 1;
		currentBoard.y = col - 1;
		cout << "You are  in board x:" << row << " and board y:" << col << endl;
	};
	TicTacToe grid[3][3];
private:
	TicTacToe board;

	Coordinate currentBoard;
};


void NBTicTacToe::displayBoards() {//Where to get the board data?
	for (int x = 0; x < 3; x++) {
		//cout << "   _  _  _  _   " << "   _  _  _  _   " << "   _  _  _  _   " << endl << endl ;
		for (int y = 0; y < 3; y++) {
			if (grid[x][y].board == grid[currentBoard.x][currentBoard.y].board) {
				cout << "# # # # # # # #";
			}
			else {
				cout << "- - - - - - - -";
			}

			//cout << "_ _ _ _ _ _ _ _";
		}
		cout << endl;
		for (int i = 0; i < 3; i++) {
			if (i % 3 == 0 && i != 0) {
				cout << endl;
			}

			if (grid[x][0].board == grid[currentBoard.x][currentBoard.y].board) {
				cout << "#";
			}
			else {
				cout << "|";
			}
			for (int u = 0; u < 3; u++) {

				for (int j = 0; j < 3; j++) {

					char playerSymbol = ' ';
					if (grid[x][u].board[i][j] == 1)
						playerSymbol = 'X';
					else if (grid[x][u].board[i][j] == -1)
						playerSymbol = 'O';
					cout << setw(3) << playerSymbol;

					if (j != 2) {
						cout << " |";
					}

				}
				if ((grid[x][u].board == grid[currentBoard.x][currentBoard.y - 1].board && currentBoard.y != 0) || grid[x][u].board == grid[currentBoard.x][currentBoard.y].board) {
					cout << "#";
				}
				else {
					cout << "|";
				}
				cout << setw(1) << ' ';
			}
			cout << endl;
			if (i != 2) {
				//cout << "|";
				cout << " ____|____|____" << " ____|____|____" << " ____|____|____";
				cout << endl << "     |    |    " << "     |    |    " << "     |    |    " << endl;

			}

		}
		for (int y = 0; y < 3; y++) {
			if (grid[x][y].board == grid[currentBoard.x][currentBoard.y].board) {
				cout << "# # # # # # # #";
			}
			else {
				cout << "- - - - - - - -";
			}
			//cout <<   "+ + + + + + + +";
		}
		cout << endl;
	}

}

bool NBTicTacToe::isValidBoard(int x, int y) {//Add your code to complete the program
	if (grid[x][y].noOfMoves >= 9 || x > 2 || x < 0 || y > 2 || y < 0) //Add your code here)
		return false;
	else
		return true;
}
void NBTicTacToe::changeBoard(int& x, int& y) {
	int min = 1;
	int max = 3;
	int row, col;
	do {
		row = (rand() % (max - min + 1)) + min;
		col = (rand() % (max - min + 1)) + min;
	} while (isValidBoard(row - 1, col - 1) == false);

	x = row - 1;
	y = col - 1;
	//cout << "You are  in board x:" << row << " and board y:" << col << endl;
}

void NBTicTacToe::play() {
	int player = 1;

	displayBoards();
	int done = 0;
	while (done == 0) {
		char playerSymbol = (player == 1) ? 'X' : 'O';
		cout << "Player " << playerSymbol << " enter move: ";
		int x, y;

		if (isValidBoard(currentBoard.x, currentBoard.y) == false) {
			cout << "You were in x Board " << currentBoard.x + 1 << " and y Board " << currentBoard.y + 1 << endl;
			changeBoard(currentBoard.x, currentBoard.y);
			cout << "Now you are in x Board " << currentBoard.x + 1 << " and y Board " << currentBoard.y + 1 << endl;

		}

		if (player == 1) {
			getXMove('X', x, y);
		}
		else {
			getOMove('O', x, y);
		}


		grid[currentBoard.x][currentBoard.y].addMove(x, y, player);
		grid[currentBoard.x][currentBoard.y].noOfMoves++;



		done = grid[currentBoard.x][currentBoard.y].gameStatus();

		currentBoard.x = x;
		currentBoard.y = y;

		displayBoards();

		int total = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				total += grid[i][j].noOfMoves;
			}
		}
		if (total >= 81) {
			done = 2;
		}

		if (done == 1) {
			cout << "Player X wins!" << endl;
		}
		else if (done == -1) {
			cout << "Player O wins!" << endl;
		}

		else if (done == 2) {
			cout << "Draw game!" << endl;
		}



		if (player == 1)
			player = -1;
		else
			player = 1;
	}
}

void NBTicTacToe::getXMove(char player, int& x, int& y) {

	int row, col;
	do {
		cin >> row >> col;
		cout << endl;
	} while (!grid[currentBoard.x][currentBoard.y].isValidMove(row - 1, col - 1));
	x = row - 1;
	y = col - 1;
	cout << "Player X entered X: " << row << " Y: " << col << endl;

	/*int min = 1;
	int max = 3;
	int row, col;
	do {
		row = (rand() % (max - min + 1)) + min;
		col = (rand() % (max - min + 1)) + min;
		cout << endl;
	} while (!grid[currentBoard.x][currentBoard.y].isValidMove(row - 1, col - 1));
	x = row - 1;
	y = col - 1;
	cout << "Player X entered X: " << row  << " Y: " << col  << endl;*/
}
void NBTicTacToe::getOMove(char playr, int& x, int& y) {
	int row, col;
	do {
		cin >> row >> col;
		cout << endl;
	} while (!grid[currentBoard.x][currentBoard.y].isValidMove(row - 1, col - 1));
	x = row - 1;
	y = col - 1;
	cout << "Player O entered X: " << row << " Y: " << col << endl;
	/*int min = 1;
	int max = 3;
	int row, col;
	do {
		row = (rand() % (max - min + 1)) + min;
		col = (rand() % (max - min + 1)) + min;
		cout << endl;
	} while (!grid[currentBoard.x][currentBoard.y].isValidMove(row - 1, col - 1));
	x = row - 1;
	y = col - 1;
	cout << "X: " << row - 1 << "Y: " << col - 1 << endl;*/

}

#endif /* TICTACTOE_H_ */