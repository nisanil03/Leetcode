class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) 
    {
        int size = nums.size();
        if(size % 3 != 0)
        return vector<vector<int>>();

        sort(nums.begin(),nums.end());

        vector<vector<int>> result (size / 3,vector<int>(3));
        int gI = 0;
        for(int i = 0; i <size; i += 3){
            if(i + 2 <size && nums[i + 2] - nums[i] <= k)
            {
                result[gI] = {nums[i] , nums [i + 1], nums[i + 2]};
                gI++;
            }
            else
            {
                return vector<vector<int>>();
            }
        }
        return result;
    }
};