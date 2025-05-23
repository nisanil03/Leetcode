class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
      long long totalsum = 0;
      int count = 0;
      int positivemin = INT_MAX;
      int negativemax = INT_MIN;

      for(int nodeValue : nums){
        int nodeValAfterOperation = nodeValue ^ k;
        totalsum += nodeValue;
        int netchange = nodeValAfterOperation - nodeValue;

        if(netchange > 0){
            positivemin = min(positivemin , netchange);
            totalsum += netchange;
            count += 1;
        }
        else{
            negativemax = max(negativemax , netchange);
        }
      }  
      if(count % 2 == 0){
        return totalsum;
      }
      return max(totalsum - positivemin , totalsum + negativemax);
    }
};