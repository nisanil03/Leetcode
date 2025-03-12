class Solution {
public:
    int maximumCount(vector<int>& nums) {
        const int n = nums.size();
        int r = upper_bound(nums.begin() , nums.end(), 0) - nums.begin();
        int l = lower_bound(nums.begin() , nums.end() ,0) - nums.begin();
        return max(n - r , l);
    }
};