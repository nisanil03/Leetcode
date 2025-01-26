class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        const int n=favorite.size();
        vector<int> deg(n, 0);
        for (int x: favorite)
            deg[x]++;
        //Kahn's Algo finds longest chain
        queue<int> q;
        for(int i=0; i<n; i++)
            if (deg[i]==0) q.push(i);// leaf node
        
        vector<int> chain(n, 1);
        for(int d=1; !q.empty(); d++){
            int qz=q.size();
            for(int a=0; a<qz; a++){
                int i=q.front();
                q.pop();
                int j=favorite[i];
                chain[j]=max(d+1, chain[j]);
                if(--deg[j]==0) q.push(j);
            }
        }
        //Find longest cyle & chains combined by 2-cycle
        int maxCycle=0, join2cycle=0;
        for (int i=0; i<n; i++){
            if (deg[i]==0) continue; //visited
            int cycleLen=0;
            for(int j=i; deg[j]!=0; j=favorite[j]){
                deg[j]=0;// mark as visited
                cycleLen++;
            }
            if (cycleLen>2) maxCycle=max(maxCycle, cycleLen);
            else join2cycle+=chain[i]+chain[favorite[i]];
        }
        return max(maxCycle, join2cycle);
    }
};