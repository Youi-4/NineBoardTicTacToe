#ifndef TICTACTOE_H_
#define TICTACTOE_H_

const int BOARDSIZE = 3;

class TicTacToe {
public:
	int noOfMoves;
	int board[BOARDSIZE][BOARDSIZE];
	TicTacToe();
	bool isValidMove(int, int);
	void addMove(int, int, int);
	int gameStatus();
	int play();
	void displayBoard();
};

TicTacToe::TicTacToe() {//How to call this function?
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			board[row][col] = 0;

	noOfMoves = 0;
}




bool TicTacToe::isValidMove(int x, int y) {//Add your code to complete the program
	if (board[x][y] == 1 || board[x][y] == -1 || x > 2 || x < 0 || y > 2 || y < 0) //Add your code here)
		return false;
	else
		return true;
}



void TicTacToe::addMove(int x, int y, int player) {//What is this function for?
	board[x][y] = player;
}

int TicTacToe::gameStatus() {

	if (board[0][0] == 1 && board[0][1] == 1 && board[0][2] == 1) {
		return 1;
	}
	if (board[1][0] == 1 && board[1][1] == 1 && board[1][2] == 1) {
		return 1;
	}
	if (board[2][0] == 1 && board[2][1] == 1 && board[2][2] == 1) {
		return 1;
	}
	if (board[0][0] == -1 && board[0][1] == -1 && board[0][2] == -1) {
		return -1;
	}
	if (board[1][0] == -1 && board[1][1] == -1 && board[1][2] == -1) {
		return -1;
	}
	if (board[2][0] == -1 && board[2][1] == -1 && board[2][2] == -1) {
		return -1;
	}

	//Check columns for a win

	//Add your code here
	if (board[0][0] == 1 && board[1][0] == 1 && board[2][0] == 1) {
		return 1;
	}
	if (board[0][1] == 1 && board[1][1] == 1 && board[2][1] == 1) {
		return 1;
	}
	if (board[0][2] == 1 && board[1][2] == 1 && board[2][2] == 1) {
		return 1;
	}
	if (board[0][0] == -1 && board[1][0] == -1 && board[2][0] == -1) {
		return -1;
	}
	if (board[1][0] == -1 && board[1][1] == -1 && board[2][1] == -1) {
		return -1;
	}
	if (board[0][2] == -1 && board[1][2] == -1 && board[2][2] == -1) {
		return -1;
	}
	//Check diagonals for a win

	//Add your code here
	if (board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1) {
		return 1;
	}
	if (board[0][2] == 1 && board[1][1] == 1 && board[2][0] == 1) {
		return 1;
	}
	if (board[0][0] == -1 && board[1][1] == -1 && board[2][2] == -1) {
		return -1;
	}
	if (board[0][2] == -1 && board[1][1] == -1 && board[2][0] == -1) {
		return -1;
	}


	return 0;
}


#endif /* TICTACTOE_H_ */