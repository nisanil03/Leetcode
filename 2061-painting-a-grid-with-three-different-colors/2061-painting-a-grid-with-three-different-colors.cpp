class Solution {
public:
    int colorTheGrid(int m, int n) {
        const int MOD = 1e9 + 7;
        vector<int> states;
        function<void(int,int,int)> dfs = [&](int pos, int prev_color, int mask) {
            if (pos == m) {
                states.push_back(mask);
                return;
            }
            for (int color = 0; color < 3; ++color) {
                if (color != prev_color) {
                    dfs(pos + 1, color, mask * 3 + color);
                }
            }
        };
        dfs(0, -1, 0);
        int S = states.size();
        vector<vector<int>> compat(S);
        // build compatibility graph
        for (int i = 0; i < S; ++i) {
            for (int j = 0; j < S; ++j) {
                int x = states[i], y = states[j];
                bool ok = true;
                for (int k = 0; k < m; ++k) {
                    if (x % 3 == y % 3) { ok = false; break; }
                    x /= 3; y /= 3;
                }
                if (ok) compat[i].push_back(j);
            }
        }
        vector<int> dp(S, 1), new_dp;
        for (int t = 0; t < n - 1; ++t) {
            new_dp.assign(S, 0);
            for (int i = 0; i < S; ++i) {
                if (dp[i]) {
                    for (int j : compat[i]) {
                        new_dp[j] = (new_dp[j] + dp[i]) % MOD;
                    }
                }
            }
            dp.swap(new_dp);
        }
        long long ans = 0;
        for (int v : dp) ans = (ans + v) % MOD;
        return ans;
    }
};