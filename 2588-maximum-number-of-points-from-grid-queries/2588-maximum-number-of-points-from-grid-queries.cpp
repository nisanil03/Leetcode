class Solution {
public:
    using int2=pair<int, int>;
    inline static int idx(int i, int j, int c){ return i*c+j; }
    inline static bool isOutside(int i, int j, int r, int c){
        return 0>i||i>=r||0>j||j>=c;
    }
    constexpr static int dir[5]={0, 1, 0, -1, 0};

    static vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        const int r=grid.size(), c=grid[0].size(), k=queries.size();
        vector<int2> qIdx(k);
        for(int i=0; i<k; i++) 
            qIdx[i]={queries[i], i};

        sort(qIdx.begin(), qIdx.end());

        priority_queue<int2, vector<int2>, greater<>> pq;
        bitset<100000> viz=0;
        pq.emplace(grid[0][0], 0);
        viz[0]=1;
        int cnt=0;
        vector<int> ans(k, 0);
        for(auto& [x, qi]: qIdx){
            while (!pq.empty() && pq.top().first<x){
                auto [v, ij]=pq.top();
                pq.pop();
                auto [i, j]=div(ij, c);
                cnt++;
                for(int a=0; a<4; a++){
                    const int s=i+dir[a], t=j+dir[a+1], st=idx(s, t, c);
                    if (isOutside(s, t, r, c)|| viz[st]) continue;
                    pq.emplace(grid[s][t], st);
                    viz[st]=1;
                }
            }
            ans[qi]=cnt;
        }
        return ans;
    }
};