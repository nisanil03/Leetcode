#include <vector>
#include <cstring>
using namespace std;

class Solution {
private:
    long rec(int i, vector<vector<int>>& questions, vector<long>& dp, int n) {
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];

        long take = questions[i][0] + rec(i + questions[i][1] + 1, questions, dp, n);
        long dont = rec(i + 1, questions, dp, n);

        return dp[i] = max(take, dont);
    }

public:
    long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long> dp(n, -1);
        return rec(0, questions, dp, n);
    }
};