class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
       int m = grid.size();

       int n =grid[0].size(); 
       int row = m-1,col = 0;
       int ans =0;
       while(row>= 0 && col<n){
           if(grid[row][col]<0)
           {
               ans+=(n-col);
               row--;
           }
           else{
               col++;
           }
       }
       return ans;
    }
};