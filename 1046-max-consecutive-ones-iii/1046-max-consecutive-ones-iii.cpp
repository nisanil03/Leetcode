class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int s = 0, mid =0;
        int ans =0;
        for(int end =0;end<nums.size();end++){
            if(nums[end]==0){
                mid++;
            }
            while(mid>k){
                if(nums[s]==0){
                    mid--;
                }
                s++;
            }
            ans=max(end-s+1,ans);
        }
        return ans;
    }
};