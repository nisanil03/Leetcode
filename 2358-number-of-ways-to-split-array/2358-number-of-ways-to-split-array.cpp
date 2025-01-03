class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long leftSideSum = 0, rightSideSum = 0;
        for(int num : nums){
            rightSideSum += num;
        }
        int validSplits = 0;

        for(int i = 0 ; i < nums.size() - 1 ; i++){
            leftSideSum += nums[i];
            rightSideSum -= nums[i];

            if(leftSideSum >= rightSideSum){
                validSplits++;
            }
        }
        return validSplits;
    }
};