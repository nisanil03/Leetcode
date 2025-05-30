const int N=100000;
unsigned dist1[N], dist2[N];
class Solution {
public:
    static void dfs0(int node, vector<int>& edges, unsigned* dist){
        for(int d=0, i=node; i!=-1 && dist[i]==UINT_MAX; d++, i=edges[i]) 
            dist[i]=d; 
    }
    static int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        const int n=edges.size();

        memset(dist1, -1, n*4);
        memset(dist2, -1, n*4);
        dfs0(node1, edges, dist1);
        dfs0(node2, edges, dist2);
        unsigned minD=UINT_MAX;
        int index=-1;
        for (int i=0; i<n; i++) {
            int max12=max(dist1[i], dist2[i]);
            if (max12<minD ) {
                minD=max12;
                index=i;
            }
        }
        return index;
    }
};