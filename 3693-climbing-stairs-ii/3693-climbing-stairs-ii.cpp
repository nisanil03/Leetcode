class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        costs.insert(costs.begin(), 0);
        int a = costs[n], b = INT_MAX / 2, c = INT_MAX / 2;  // dp[i + 1], dp[i + 2], dp[i + 3] for i = n - 1
        for (int i = n - 1; i >= 0; --i) {
            int cur = costs[i] + min({a + 1, b + 4, c + 9});  // dp[i]
            c = b, b = a, a = cur;
        }
        return a;
    }
};