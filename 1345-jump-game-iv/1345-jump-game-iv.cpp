class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        if(n==1)return 0;
        unordered_map<int,vector<int>>mp;
        for (int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        queue<pair<int,int>>q;
        q.push({0,0});
        vector<int>vis(n,0);
        vis[0]=1;
        while(!q.empty()){
            int node=q.front().first;
            int dist=q.front().second;
            q.pop();
            if(node==n-1)return dist;
            if(node-1>=0 && !vis[node-1]){
                vis[node-1]=1;
                q.push({node-1,dist+1});
            }
            if(node+1<n && !vis[node+1]){
                vis[node+1]=1;
                q.push({node+1,dist+1});
            }
            for (int next:mp[arr[node]]){
                if (!vis[next]){
                    vis[next]=1;
                    q.push({next,dist+1});
                }
            }
            mp[arr[node]].clear();
        }
        return -1;
    }
};