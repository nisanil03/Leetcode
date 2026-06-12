class Solution {
public:
    vector<int>per,depth;
    vector<vector<int>>up;
    int LOG=20;
    const int MOD=1e9+7;
    int power(long long a,long long b){
        long long ans=1;
        a%=MOD;
        while(b>0){
            if(b&1)ans=(ans*a)%MOD;
            a=(a*a)%MOD;
            b>>=1;
        }
        return (int)ans;
    }

    int countWays(int d){
        if(d==0)return 0;
        return power(2,d-1);
    }

    void dfs(int node,int p,vector<vector<int>>&adj){
        per[node]=p;
        up[node][0]=p;
        for(int j=1;j<LOG;j++){
            if(up[node][j-1]!=-1)up[node][j]=up[up[node][j-1]][j-1];
        }
        for(auto&it:adj[node]){
            if(it!=p){
                depth[it]=depth[node]+1;
                dfs(it,node,adj);
            }
        }
    }

    int lca(int u,int v){
        if(depth[u]<depth[v])swap(u,v);
        int diff=depth[u]-depth[v];
        for(int j=0;j<LOG;j++){
            if(diff&(1<<j))
                u=up[u][j];
        }
        if(u==v)
            return u;
        for(int j=LOG-1;j>=0;j--){
            if(up[u][j]!=up[v][j]){
                u=up[u][j];
                v=up[v][j];
            }
        }
        return up[u][0];
    }

    int dist(int u,int v){
        int L=lca(u,v);
        int d=depth[u]+depth[v]-2*depth[L];
        return countWays(d);
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n=edges.size()+2;
        vector<vector<int>>adj(n);
        for(auto&edge:edges){
            int u=edge[0],v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        per.resize(n,-1);
        depth.resize(n,0);
        up.resize(n,vector<int>(LOG,-1));
        dfs(1,-1,adj);
        vector<int>ans;
        for(auto&q:queries){
            int u=q[0],v=q[1];
            ans.push_back(dist(u,v));
        }
        return ans;
    }
};