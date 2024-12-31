class Solution {
    public:
     int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1 , 0);

        for(int i = 0; i < n ; ++i){
            int cost1 = dp[i] + costs[0];

            int j = i;
            while(j >= 0 && days[j] >= days[i] - 6) --j;
            int cost7 = dp[j + 1] + costs[1];

            j = i;
            while(j >= 0 && days[j] >= days[i] - 29) --j;
            int cost30 = dp[j + 1] + costs[2];

            dp[i + 1] = min({cost1 , cost7 , cost30});
        }
        return dp[n];
    }
};