class Solution {
public:

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n= moveTime.size();
        int m= moveTime[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,0,0,0});
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        dis[0][0]=0;
        while(!pq.empty())
        {
            auto it=pq.top();
            int time=it[0];
            int r=it[1];
            int c=it[2];
            int flag=it[3];
            pq.pop();
            if(r==n-1 and c==m-1) return time;
            for(int i=0;i<4;i++)
            {
                int nr=r+dx[i];
                int nc=c+dy[i];
                if(nr>=0 and nr<n and nc>=0 and nc<m)
                {
                    int ntime=max(time,moveTime[nr][nc]) + ((flag&1)? 2:1);
                    if(dis[nr][nc]>ntime)
                    {
                        dis[nr][nc]=ntime;
                        pq.push({ntime,nr,nc,flag+1});
                    }
                }
            }
        }
        return -1;

    }
};