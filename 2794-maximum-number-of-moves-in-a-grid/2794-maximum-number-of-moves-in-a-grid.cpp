class Solution {
public:
  vector<vector<int>> dp;
  int n , m ;
  int f(int i , int j , int prev , vector<vector<int>> & grid){
    if(i < 0 || j<0 || i>= n || j >= m) return 0;
    int x =  grid[i][j];
    if(x<=prev) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    return dp[i][j] = 1 + max({f(i-1 , j +1 , x , grid),
    f(i , j +1 , x , grid),
    f(i+1 , j+1 , x , grid)});
  }
    int maxMoves(vector<vector<int>>& grid) {
        n = grid.size() , m = grid[0].size();
        dp.assign(n , vector<int>(m, -1));
        int ans =0;
        for(int i = 0; i < n ; i++)
           ans =max(ans , f(i , 0 , -1 , grid));
        return ans-1;
    }
};