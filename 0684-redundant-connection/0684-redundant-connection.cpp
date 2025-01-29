class DisjointSet {
    vector<int> parent, depth;
public:
    DisjointSet(int n) : parent(n), depth(n) {
        depth.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int getRoot(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = getRoot(parent[x]);
    }

    bool merge(int x, int y) {
        int rootX = getRoot(x), rootY = getRoot(y);
        if (rootX == rootY)
            return false;
        if (depth[rootX] > depth[rootY])
            swap(rootX, rootY);
        parent[rootX] = rootY;
        if (depth[rootX] == depth[rootY])
            depth[rootY]++;
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n + 1);
        for (auto& edge : edges)
            if (!ds.merge(edge[0], edge[1])) return edge;
        return {};
    }
};