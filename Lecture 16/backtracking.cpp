#include <iostream>

using namespace std;

bool isSafe(int board[4][4], int row, int col, int n) {

	// COLUMN
	for (int i = row; i >= 0; i--) {
		if (board[i][col] == 1) {
			return false;
		}
	}

	// LEFT DIAGONALS

	int x = row;
	int y = col;

	while (x >= 0 and y >= 0) {
		// cout << "( " << x << "," << y << " )" << " -> " << board[x][y] << endl;

		if (board[x][y] == 1) {
			return false;
		}

		x--;
		y--;
	}

	// cout << "Loop has ended" << endl;

	// RIGHT DIAGONALS

	x = row;
	y = col;

	while (x >= 0 and y < n) {

		if (board[x][y] == 1) {
			return false;
		}

		x--;
		y++;
	}

	return true;
}

bool NQueens(int board[4][4], int row, int n) {
	//BASE CASE
	if (row == n) {
		//PRINT

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {

				if (board[i][j]) {
					cout << "Q ";
				} else {
					cout << "_ ";
				}
			}
			cout << endl;
		}

		cout << "********************************" << endl;

		return true;// for printing convert to -> return false;
	}


	//RECURSIVE CASE
	for (int col = 0; col < n; col++) {

		// row = 1
		// col = 2->3

		if (isSafe(board, row, col, n)) {

			board[row][col] = 1; // my work

			bool rest_of_the_queens = NQueens(board, row + 1, n); // recursion

			// if (rest_of_the_queens) { // if orientation is correct
			// 	return true; 			// return true
			// }

			// if we here that means the subproblem was false
			board[row][col] = 0; // remove your current queen !BACKTRAKCING!
		}

	}

	return false;
}

int countNQueens(int board[4][4], int row, int col, int n) {
	//HOMEWORK
	return 0;
}

bool ratInAMaze(char maze[4][4], int sr, int sc, int er, int ec, int sol[4][4]) {
	//BASE CASE
	if (sr == er and sc == ec) {
		return true;
	}

	if (sr > er or sc > ec) {
		return false;
	}

	if (maze[sr][sc] == 'X') {
		return false;
	}

	// RECURSIVE CASE
	bool rightMove = ratInAMaze(maze, sr, sc + 1, er, ec, sol);
	bool downMove = ratInAMaze(maze, sr + 1, sc, er, ec, sol);

	if (rightMove or downMove) {
		return true;
	}

	return false;
}

int main() {

	// int board[4][4] = {0};
	// int n = 4;

	// cout << NQueens(board, 0, n) << endl;

	int n = 4;
	char maze[4][4] = { {'0', '0', '0', 'X'},
		{'0', '0', 'X', '0'},
		{'0', 'X', '0', '0'},
		{'X', '0', '0', '0'}
	};

	cout << ratInAMaze(maze, 0, 0, n - 1, n - 1) << endl;

	return 0;
}