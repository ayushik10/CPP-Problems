/*  1351.  COUNT NEGATIVE NUMBERS IN A SORTED MATRIX.

Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

Example 1:

Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.
Example 2:

Input: grid = [[3,2],[1,0]]
Output: 0
 
Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 100
-100 <= grid[i][j] <= 100         */
 

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
       int row = grid.size();
       int col = grid[0].size();
       int total = 0;

       for(int i = 0; i<row; i++){
     
           int s=0;
           int e=col-1;
           int count = 0;
           int ans = col;
           
       while(s<=e){
          
           int mid = (s+e)/2;

           if(grid[i][mid] >= 0){
               s = mid+1;
               count = row-s;
           }
           else {
               ans = mid;
               e = mid-1;
           
           }
       }
       total = total+(col-ans);
       }
       return total; 
    }
};
