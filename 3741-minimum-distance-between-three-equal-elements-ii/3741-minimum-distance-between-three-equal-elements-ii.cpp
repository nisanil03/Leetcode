const int N=1e5+1;
int pos[N][2]={[0 ... N-1][0 ... 1]=-1};
class Solution {
public:
    static int minimumDistance(vector<int>& nums) {
        const int n=nums.size();
        int ans=INT_MAX, M=0;
        for(int k=0; k<n; k++){
            const int x=nums[k];
            M=max(M, x);
            if (pos[x][1]!=-1){
                ans=min(ans, (k-pos[x][1])<<1);
            }
            pos[x][1]=exchange(pos[x][0], k);
        }
        memset(pos, -1, sizeof(int)*2*(M+1));
        return ans==INT_MAX?-1:ans;
    }
};