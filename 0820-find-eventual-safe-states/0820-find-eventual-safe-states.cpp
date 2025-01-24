class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n);
        vector<int> safe;

        for(int i = 0; i < n; ++i)
           if(dfs(graph,i,state))
           safe.push_back(i);

           return safe;
    }
private:
   bool dfs(vector<vector<int>> & graph, int node , vector<int>& state){
    if(state[node] > 0) return state[node] == 2;

    state[node] = 1;

    for(int next : graph[node])
    if(state[next] == 1 || !dfs(graph , next, state))
        return false;

    state[node] = 2;
    return true;
   }
};