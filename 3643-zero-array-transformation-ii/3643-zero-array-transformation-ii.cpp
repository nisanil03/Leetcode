
class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size(),q=queries.size();
        if(count(nums.begin(),nums.end(),0)==n)return 0; 
        auto check=[&](int mid){
            vector<int>diff(n+1,0),cur(nums);
            for(int i=0;i<mid;i++){
                int l=queries[i][0],r=queries[i][1],val=queries[i][2];
                diff[l]-=val;
                diff[r+1]+=val;
            }
            int sum=0,zeroCount=0;
            for(int i=0;i<n;i++){
                sum+=diff[i];
                cur[i]=max(0,cur[i]+sum);
                if(cur[i]==0)zeroCount++;
            }
            return zeroCount==n;
        };
        int lo=1,hi=q,ans=-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(check(mid)){ans=mid;hi=mid-1;}
            else lo=mid+1;
        }
        return ans;
    }};