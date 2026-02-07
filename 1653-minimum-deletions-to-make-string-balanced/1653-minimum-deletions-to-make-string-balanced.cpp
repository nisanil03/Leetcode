class Solution {
public:
// MEMOISATION
//  int solve(int index, int n , string& s , bool flag ,vector<vector<int>> &dp){
//     if(index == n) return 0;
//     int mini = 1e9;
//     if(dp[index][flag] != -1) return dp[index][flag];
//     // inclue
//     if(s[index] == 'a' && flag == false){
//         int element = solve(index +1 , n ,s, flag,dp);
//         mini = min(mini , element);
//     }
//     else if (s[index] =='b'){
//         int element = solve(index+1, n, s,true,dp);
//         mini = min(mini , element);
//     }
//     // exclue
//     int element = 1 + solve(index +1 , n , s,flag , dp);
//     mini = min(mini , element);
//     return dp[index][flag] = mini;
//  }
    int minimumDeletions(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n = s.size();
        // vector<vector<int>> dp(n,vector<int>(2,-1));
        // bool flag = false;
        // return solve(0,n,s,flag,dp);

//TABULATION 

    //     vector<vector<int>> dp(n+1 , vector<int>(2,0));
    //     bool flag = false;
    //     for(int i = n-1 ; i>= 0 ;i--){
    //         for(int flag = 0; flag <= 1; flag++){
    //             int mini  =1e9;
    //             if(s[i] =='a' && flag ==0){
    //                 int element = dp[i+1][flag];
    //                 mini = min(mini , element);
    //             }
    //             else if (s[i] =='b'){
    //                 int element = dp[i+1][1];
    //                 mini = min(mini , element);
    //             }
    //             // exclue
    //             int element = 1+dp[i+1][flag];
    //             mini = min(mini ,element);
    //             dp[i][flag] = mini;
    //         }
    //     }
    //     return dp[0][0];

// space optimization 
        int ans = 0;
        int count_b = 0;
        for(int i = 0; i <n;i++){
            if(s[i] == 'b')count_b++;
            else{
                ans = min(ans+1,count_b);
            }
        }
        return ans;
    }
};