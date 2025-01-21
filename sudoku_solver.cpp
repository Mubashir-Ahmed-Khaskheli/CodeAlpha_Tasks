#include <iostream>
#include <vector>
using namespace std;

void print_board(const vector<vector<int> > & board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool is_valid(const vector<vector<int> > & board, int row, int col, int num) {

    for (int c = 0; c < 9; ++c) {
        if (board[row][c] == num) return false;
    }

    for (int r = 0; r < 9; ++r) {
        if (board[r][col] == num) return false;
    }

    int box_row_start = (row / 3) * 3;
    int box_col_start = (col / 3) * 3;
    for (int r = box_row_start; r < box_row_start + 3; ++r) {
        for (int c = box_col_start; c < box_col_start + 3; ++c) {
            if (board[r][c] == num) return false;
        }
    }
    return true;
}

bool solve_sudoku(vector<vector<int> > & board) {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= 9; ++num) {
                    if (is_valid(board, row, col, num)) {
                        board[row][col] = num;
                        if (solve_sudoku(board)) return true;
                        board[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<int> > board;
    vector<int> row1;
    row1.push_back(5);
    row1.push_back(3);
    row1.push_back(0);
    row1.push_back(0);
    row1.push_back(7);
    row1.push_back(0);
    row1.push_back(0);
    row1.push_back(0);
    row1.push_back(0);

    vector<int> row2;
    row2.push_back(6);
    row2.push_back(0);
    row2.push_back(0);
    row2.push_back(1);
    row2.push_back(9);
    row2.push_back(5);
    row2.push_back(0);
    row2.push_back(0);
    row2.push_back(0);

    vector<int> row3;
    row3.push_back(0);
    row3.push_back(9);
    row3.push_back(8);
    row3.push_back(0);
    row3.push_back(0);
    row3.push_back(0);
    row3.push_back(0);
    row3.push_back(6);
    row3.push_back(0);

    vector<int> row4;
    row4.push_back(8);
    row4.push_back(0);
    row4.push_back(0);
    row4.push_back(0);
    row4.push_back(6);
    row4.push_back(0);
    row4.push_back(0);
    row4.push_back(0);
    row4.push_back(3);

    vector<int> row5;
    row5.push_back(4);
    row5.push_back(0);
    row5.push_back(0);
    row5.push_back(8);
    row5.push_back(0);
    row5.push_back(3);
    row5.push_back(0);
    row5.push_back(0);
    row5.push_back(1);

    vector<int> row6;
    row6.push_back(7);
    row6.push_back(0);
    row6.push_back(0);
    row6.push_back(0);
    row6.push_back(2);
    row6.push_back(0);
    row6.push_back(0);
    row6.push_back(0);
    row6.push_back(6);

    vector<int> row7;
    row7.push_back(0);
    row7.push_back(6);
    row7.push_back(0);
    row7.push_back(0);
    row7.push_back(0);
    row7.push_back(0);
    row7.push_back(2);
    row7.push_back(8);
    row7.push_back(0);

    vector<int> row8;
    row8.push_back(0);
    row8.push_back(0);
    row8.push_back(0);
    row8.push_back(4);
    row8.push_back(1);
    row8.push_back(9);
    row8.push_back(0);
    row8.push_back(0);
    row8.push_back(5);

    vector<int> row9;
    row9.push_back(0);
    row9.push_back(0);
    row9.push_back(0);
    row9.push_back(0);
    row9.push_back(8);
    row9.push_back(0);
    row9.push_back(0);
    row9.push_back(7);
    row9.push_back(9);
    board.push_back(row1);
    board.push_back(row2);
    board.push_back(row3);
    board.push_back(row4);
    board.push_back(row5);
    board.push_back(row6);
    board.push_back(row7);
    board.push_back(row8);
    board.push_back(row9);

    cout << "*** Original Sudoku Board: ***" << endl;
    print_board(board);
    if (solve_sudoku(board)) {
        cout << "*** Solved Sudoku Board: ***" << endl;
        print_board(board);
    } else {
        cout << "No solution exists" << endl;
    }
    return 0;
}
