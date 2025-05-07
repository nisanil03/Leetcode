class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n=moveTime.size();
        int m=moveTime[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>qu; //{t,{r,c}}
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        qu.push({0,{0,0}});
        while(!qu.empty()){
            int t=qu.top().first;
            int row=qu.top().second.first;
            int col=qu.top().second.second;
            qu.pop();
            if(row==n-1 && col==m-1) return t;
            int drow[4]={0,-1,0,1};
            int dcol[4]={-1,0,1,0};
            for(int i=0;i<4;i++){
                int n_row=row+drow[i];
                int n_col=col+dcol[i];
                
                if(n_row>=0 && n_row<n && n_col>=0 && n_col<m ){
                    int diff=max(t,moveTime[n_row][n_col])+1;
                    
                    if(diff<dist[n_row][n_col]){
                        dist[n_row][n_col]=diff;
                        qu.push({diff,{n_row,n_col}});
                    }
                    
                }
            }
        }
        
        return -1;
    }
};