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
