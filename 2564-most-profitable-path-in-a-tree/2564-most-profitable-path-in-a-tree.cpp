vector<int> adj[100000];
int parent[100000], Bob[100000];

class Solution {
public:
    void dfs(int i, int p) {
        parent[i]=p;
        for (int j : adj[i]) {
            if (j==p) continue;
            dfs(j, i);
        }
    }

    int dfs_sum(int i, int dist, int prev, vector<int>& amount) {
        int alice=0;

        if (dist < Bob[i]) alice=amount[i];  // Alice gets full amount
        else if (dist == Bob[i]) alice= amount[i]/2;  // Split with Bob

        bool isLeaf=1;// set isLeaf flag
        int maxLeafSum=INT_MIN;

        for (int j : adj[i]) {
            if (j==prev) continue;
            isLeaf=0;// has child=> no leaf
            maxLeafSum = max(maxLeafSum, dfs_sum(j, dist+1, i, amount));
        }

        return alice+(isLeaf?0:maxLeafSum);
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        const int n=edges.size()+1;

        for (int i=0; i < n; i++) adj[i].clear();

        for (auto& e : edges) {
            int u=e[0], v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0, -1);

        // Compute Bob's reach time
        fill(Bob, Bob+n, INT_MAX);
        for (int x=bob, move=0; x != -1; x=parent[x]) {
            Bob[x]=move++;
        }

        return dfs_sum(0, 0, -1, amount);
    }
};
