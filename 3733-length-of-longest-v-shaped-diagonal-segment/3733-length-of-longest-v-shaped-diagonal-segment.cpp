class Solution {
public:
    int lenOfVDiagonal(std::vector<std::vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        // directions: 0:↘ (1,1), 1:↖ (-1,-1), 2:↙ (1,-1), 3:↗ (-1,1)
        int di[4] = { 1, -1, 1, -1 };
        int dj[4] = { 1, -1, -1, 1 };
        int cw[4] = { 2, 3, 1, 0 }; // clockwise(d)
        
        // endLen[d][i][j]: longest straight valid (starting with 1) ending at (i,j) with last move dir d
        std::vector endLen(4, std::vector(n, std::vector<int>(m, 0)));

        // alt2[d][i][j], alt0[d][i][j]: alternating lengths starting at (i,j) expecting 2 or 0 along dir d
        std::vector alt2(4, std::vector(n, std::vector<int>(m, 0)));
        std::vector alt0(4, std::vector(n, std::vector<int>(m, 0)));

        auto inb = [&](int x, int y){ return (0 <= x && x < n && 0 <= y && y < m); };

        // 1) Compute endLen for each direction with predecessor-based DP
        for (int d = 0; d < 4; ++d) {
            int si = (di[d] == 1 ? 0 : n-1);
            int ei = (di[d] == 1 ? n : -1);
            int stepi = (di[d] == 1 ? 1 : -1);
            int sj = (dj[d] == 1 ? 0 : m-1);
            int ej = (dj[d] == 1 ? m : -1);
            int stepj = (dj[d] == 1 ? 1 : -1);

            for (int i = si; i != ei; i += stepi) {
                for (int j = sj; j != ej; j += stepj) {
                    int bestHere = 0;
                    if (grid[i][j] == 1) bestHere = 1; // start new segment here

                    int pi = i - di[d], pj = j - dj[d];
                    if (inb(pi, pj) && endLen[d][pi][pj] > 0) {
                        int Lprev = endLen[d][pi][pj];
                        int expected = (Lprev % 2 ? 2 : 0);
                        if (grid[i][j] == expected) {
                            bestHere = std::max(bestHere, Lprev + 1);
                        }
                    }
                    endLen[d][i][j] = bestHere;
                }
            }
        }

        // 2) Compute alternating tails (alt2 / alt0) for each direction using successor-based DP
        for (int d = 0; d < 4; ++d) {
            int si = (di[d] == 1 ? n-1 : 0);
            int ei = (di[d] == 1 ? -1 : n);
            int stepi = (di[d] == 1 ? -1 : 1);
            int sj = (dj[d] == 1 ? m-1 : 0);
            int ej = (dj[d] == 1 ? -1 : m);
            int stepj = (dj[d] == 1 ? -1 : 1);

            for (int i = si; i != ei; i += stepi) {
                for (int j = sj; j != ej; j += stepj) {
                    int ni = i + di[d], nj = j + dj[d];
                    int a2 = 0, a0 = 0;
                    if (grid[i][j] == 2) {
                        a2 = 1 + (inb(ni, nj) ? alt0[d][ni][nj] : 0);
                    }
                    if (grid[i][j] == 0) {
                        a0 = 1 + (inb(ni, nj) ? alt2[d][ni][nj] : 0);
                    }
                    alt2[d][i][j] = a2;
                    alt0[d][i][j] = a0;
                }
            }
        }

        // 3) Combine: take max of straight segments and V-shaped with a clockwise turn
        int best = 0;
        // straight (no turn)
        for (int d = 0; d < 4; ++d)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    best = std::max(best, endLen[d][i][j]);

        // one clockwise turn at (i,j): first arm ends at (i,j) in d1, then continue in d2 = cw[d1]
        for (int d1 = 0; d1 < 4; ++d1) {
            int d2 = cw[d1];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    int L1 = endLen[d1][i][j];
                    if (L1 == 0) continue;
                    int ni = i + di[d2], nj = j + dj[d2];
                    int extra = 0;
                    if (inb(ni, nj)) {
                        int expectedNext = (L1 % 2 ? 2 : 0);
                        extra = (expectedNext == 2 ? alt2[d2][ni][nj] : alt0[d2][ni][nj]);
                    }
                    best = std::max(best, L1 + extra);
                }
            }
        }

        return best;
    }
};