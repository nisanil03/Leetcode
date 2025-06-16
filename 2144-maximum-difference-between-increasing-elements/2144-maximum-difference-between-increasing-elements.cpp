class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int diff = -1;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            for(int j = i +1; j < n ; j++){
                if(nums[j] > nums[i]){
                    diff = max(diff , nums[j] - nums[i]);
                }
            }
        }
        return diff;
    }
};