class Solution {
public:
    int check(vector<int>& nums, int n, int t, int m) {
        long long nL = n;
        long long tL = t;
        int l = lower_bound(nums.begin(), nums.end(), nL) - nums.begin();
        int h = upper_bound(nums.begin(), nums.end(), nL) - nums.begin();
        int ll = lower_bound(nums.begin(), nums.end(), nL - tL) - nums.begin();
        int hh = upper_bound(nums.begin(), nums.end(), nL + tL) - nums.begin();
        int res = (hh - h) + (l - ll);
        return min(m, res) + (h - l);
    }

    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int m = numOperations;
        sort(nums.begin(), nums.end());
        int ans = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            ans = max(check(nums, nums[i], k, m), ans);
            ans = max(check(nums, nums[i] - k, k, m), ans);
            ans = max(check(nums, nums[i] + k, k, m), ans);
        }
        return ans;
    }
};