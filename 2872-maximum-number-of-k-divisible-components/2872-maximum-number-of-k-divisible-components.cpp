class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int> > G(n);
        for(auto edge : edges){
            G[edge[0]].push_back(edge[1]);
            G[edge[1]].push_back(edge[0]);
        }
        stack <int> S;
        vector<int> parent(n);
        
        auto DFS = [&](int u, int p, auto &&DFS) -> void{
            parent[u] = p;
            S.push(u);
            for(auto v : G[u]){
                if(v == p) continue;
                DFS(v, u, DFS);
            }
        };
        DFS(0, -1, DFS);
        vector<long long> sum(n);
        for(int i = 0; i < n; i ++){
            sum[i] = values[i];
        }
        int ans = 0;
        while(!S.empty()){
            int u = S.top();
            S.pop();
            if(sum[u] % k == 0){
                ans += 1;
            }
            else{
                sum[parent[u]] += sum[u];
            }
        }
        return ans;
    }
};