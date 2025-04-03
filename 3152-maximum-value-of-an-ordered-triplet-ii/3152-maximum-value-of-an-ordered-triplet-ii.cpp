class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        const int n = nums.size();
        long long L = nums[0], maxD = 0 , ans = 0;
        for(int k = 1; k < n; k++){
            const long long xk = nums[k];
            ans = max(ans , maxD*xk);
            maxD = max(maxD , L-xk);
            L=max(L,xk);
        }
        return ans;
    }
};