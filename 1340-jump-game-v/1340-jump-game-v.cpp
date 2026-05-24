struct Edge{
    int to, nxt=-1;
};

constexpr int V=1000;
constexpr int E=V*2;

Edge POOL[E];
int idx=0;

int adj[V], deg[V];
int dp[V];

int q[V];// for queue holding idx
int front, back;

inline void addEdge(int u, int v){
    POOL[idx]={v, adj[u]};
    adj[u]=idx++;
    deg[v]++;
}
int Stack[V], top=-1;

class Solution {
public:
    static int maxJumps(vector<int>& arr, int d) {
        const int n=arr.size();
        // reset
        idx=0;
        memset(adj, -1, n*sizeof(int));
        memset(deg, 0, n*sizeof(int));
        fill(dp, dp+n, 1);
        // montonone stack
        top=-1;// clear stack
        for(int i=0; i<n; i++){
            const int x=arr[i];
            while(top>-1 && arr[Stack[top]]<x){
                int j=Stack[top--];
                if (i-j<=d) addEdge(j, i);
            }
            Stack[++top]=i;
        }
        top=-1;// clear Stack
        for(int i=n-1; i>=0; i--){
            const int x=arr[i];
            while(top>-1 && arr[Stack[top]]<x){
                int j=Stack[top--];
                if (j-i<=d) addEdge(j, i);
            }
            Stack[++top]=i;
        }

        front=back= 0;// reset for q
        for(int i=0; i<n; i++)// Push i to q if deg[i]=0
            if(deg[i]==0)
                q[back++]=i;

        while(front<back){
            int u=q[front++];
            for(int e=adj[u]; e!=-1; e=POOL[e].nxt){
                int v=POOL[e].to;
                dp[v]=max(dp[v], dp[u]+1);
                if(--deg[v]==0)
                    q[back++]=v;
            }
        }

        return *max_element(dp, dp+n);
    }
};