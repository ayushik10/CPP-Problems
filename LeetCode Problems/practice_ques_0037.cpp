/* 37. SUDOKU SOLVER

Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.


Example 1:
Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
Explanation: The input board is shown above and the only valid solution is shown below:


Constraints:
board.length == 9
board[i].length == 9
board[i][j] is a digit or '.'.
It is guaranteed that the input board has only one solution.                    */



class Solution {
private:
    bool isSafe(int row, int col, vector<vector<char>> &board, char val) {

        for(int i=0; i<9; i++) {
            //for row
            if(board[row][i] == val){
                return false;
            }
            
            //for column
            if(board[i][col] == val) {
                return false;
            }
            
            //for 3*3 matrix
            if(board[3*(row/3)+i/3][3*(col/3)+i%3] == val) {
                return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>> &board) {

        for(int i=0; i<board[0].size(); i++) {

            for(int j=0; j<board[0].size(); j++) {

                //check for empty space
                if(board[i][j] == '.') {

                    for(char val='1'; val<='9'; val++) {

                        if(isSafe(i, j, board, val)) {
                            board[i][j] = val;
                             
                            //recursive call 
                            bool nextSol = solve(board);

                            if(nextSol)
                            return true;

                            else 
                            //backtracking
                            board[i][j] = '.';       
                        }
                    }
                    return false;
                }
            }
            
         }
         return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
