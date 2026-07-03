class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();

        vector<vector<pair<int,int>>> graph(n);
        vector<int> indegree(n, 0);

        for (auto &e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
            indegree[e[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0)
                q.push(i);

        vector<int> topo;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);

            for (auto &[v, w] : graph[u]) {
                if (--indegree[v] == 0)
                    q.push(v);
            }
        }

        auto check = [&](int limit) {
            const long long INF = (1LL << 60);

            vector<long long> dp(n, INF);
            dp[0] = 0;

            for (int u : topo) {

                if (dp[u] == INF)
                    continue;

                if (u != 0 && u != n - 1 && !online[u])
                    continue;

                for (auto &[v, w] : graph[u]) {

                    if (w < limit)
                        continue;

                    if (v != n - 1 && !online[v])
                        continue;

                    if (dp[u] + w < dp[v])
                        dp[v] = dp[u] + w;
                }
            }

            return dp[n - 1] <= k;
        };

        int left = 0, right = 1000000000;
        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (check(mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};