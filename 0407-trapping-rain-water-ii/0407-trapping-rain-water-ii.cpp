class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty())
            return 0;

        int m = heightMap.size();
        int n = heightMap[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<>>
            minHeap;

        // \U0001f6a7 Add boundary cells to the minHeap
        for (int i = 0; i < m; ++i) {
            for (int j : {0, n - 1}) {
                minHeap.emplace(heightMap[i][j], i, j);
                visited[i][j] = true;
            }
        }
        for (int j = 0; j < n; ++j) {
            for (int i : {0, m - 1}) {
                if (!visited[i][j]) {
                    minHeap.emplace(heightMap[i][j], i, j);
                    visited[i][j] = true;
                }
            }
        }

        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int waterTrapped = 0;

        // \U0001f30a\U0001f501 Process cells using the minHeap
        while (!minHeap.empty()) {
            auto [height, x, y] = minHeap.top();
            minHeap.pop();

            for (auto& dir : directions) {
                int nx = x + dir[0], ny = y + dir[1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                    !visited[nx][ny]) {
                    // \U0001f9ee Calculate water trapped
                    waterTrapped += max(0, height - heightMap[nx][ny]);
                    minHeap.emplace(max(height, heightMap[nx][ny]), nx, ny);
                    visited[nx][ny] = true;
                }
            }
        }

        return waterTrapped; // \U0001f3c6 Final result
    }
};