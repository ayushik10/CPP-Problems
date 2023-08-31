/*  59. SPIRAL MATRIX II

Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/



class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
    vector< vector<int>> ans(n, vector<int>(n));

    int startingRow = 0;
    int startingCol = 0;
    int endingRow = n-1;
    int endingCol = n-1;

    int count = 1;
    int total = n*n;

    while (count <= total)
    {
        
        for (int i=startingCol; count<=total && i<=endingCol; i++){
            ans[startingRow][i] = count++;
            
        }
        startingRow++;
        
        for (int i=startingRow ; count<=total && i<=endingRow; i++){
            ans[i][endingCol] = count++;
        }
        endingCol--;
        
        for (int i=endingCol; count<=total && i>=startingCol; i--){
            ans[endingRow][i] = count++;
        }
        endingRow--;
        
        for (int i=endingRow; count<=total && i>=startingRow; i--){
            ans[i][startingCol] = count++;
        }
        startingCol++;
    }
    return ans;
    }
};
