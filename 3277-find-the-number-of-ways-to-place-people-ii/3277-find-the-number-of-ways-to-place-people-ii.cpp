class Solution {
public:
    int numberOfPairs(vector<vector<int>>& nums) {
      sort(nums.begin(), nums.end(), [](auto &a, auto&b){
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
      });
      int n = nums.size();
      int count = 0;

      for(int i =0; i < n; i++){
        int maxi = INT_MIN;
        for(int j = i + 1; j < n; j++){
            if(nums[j][1] > nums[i][1]) continue;
            if(nums[j][1] > maxi){
                count++;
                maxi=nums[j][1];
            }
        }
      }  
      return count;
    }
};